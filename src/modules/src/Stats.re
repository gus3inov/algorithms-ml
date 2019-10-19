open Shirts;

let map2 = (optX: 'x, optY: 'y, f): option('f) => {
  switch (optX, optY) {
  | (Some(x), Some(y)) => Some(f(x, y))
  | (_, _) => None
  };
};

let optInt = (str: string): option(int) => {
  switch (int_of_string(str)) {
  | fNum => Some(fNum)
  | exception (Failure("int_of_string")) => None
  };
};

let optFloat = (str: string): option(float) => {
  switch (float_of_string(str)) {
  | fFloat => Some(fFloat)
  | exception (Failure("float_of_string")) => None
  };
};

let lineReducer = (acc: list(order), line: string): list(order) => {
  let items = Js.String.split(",", line);
  if (Belt.Array.length(items) != 7) {
    acc;
  } else {
    let initial =
      Some({
        quantity: 0,
        size: Small,
        sleeve: Short,
        color: White,
        pattern: Solid,
        cuff: Button,
        collar: Straight,
      });

    let orderRecord =
      map2(initial, optInt(items[0]), (result, n) =>
        {...result, quantity: n}
      )
      ->map2(Size.fromString(items[1]), (result, sz) =>
          {...result, size: sz}
        )
      ->map2(Color.fromString(items[2]), (result, c) =>
          {...result, color: c}
        )
      ->map2(Pattern.fromString(items[3]), (result, pat) =>
          {...result, pattern: pat}
        )
      ->map2(Collar.fromString(items[4]), (result, coll) =>
          {...result, collar: coll}
        )
      ->map2(Sleeve.fromString(items[5]), (result, sleeve) =>
          {...result, sleeve}
        )
      ->map2(Cuff.fromString(items[6]), (result, cuff) =>
          {...result, cuff}
        );

    switch (orderRecord) {
    | Some(result) => [result, ...acc]
    | None => acc
    };
  };
};

let printMap =
    (
      title: string,
      distribution: Belt.Map.t('k, 'v, 'id),
      toString: 'a => string,
    ) => {
  Js.log2(title, "Quantity");
  Belt.Map.forEach(distribution, (key, value) =>
    Js.log2(toString(key), value)
  );
  Js.log("");
};

let printStatistics = (orders: list(order)): unit => {
  let makeDistro = (comprator, getter) => {
    Belt.List.reduce(
      orders,
      Belt.Map.make(~id=comprator),
      (acc, item) => {
        let n = Belt.Map.getWithDefault(acc, getter(item), 0);
        Belt.Map.set(acc, getter(item), n + item.quantity);
      },
    );
  };

  let colorDistribution =
    makeDistro((module ColorComparator), ord => ord.color);
  printMap("Color", colorDistribution, Color.toString);

  let sizeDistribution = makeDistro((module SizeComparator), ord => ord.size);
  printMap("Size", sizeDistribution, Size.toString);

  let patternDistribution =
    makeDistro((module PatternComparator), ord => ord.pattern);
  printMap("Pattern", patternDistribution, Pattern.toString);

  let collarDistribution =
    makeDistro((module CollarComparator), ord => ord.collar);
  printMap("Collar", collarDistribution, Collar.toString);

  let sleeveDistribution =
    makeDistro((module SleeveComparator), ord => ord.sleeve);
  printMap("Sleeve", sleeveDistribution, Sleeve.toString);

  let cuffDistribution = makeDistro((module CuffComparator), ord => ord.cuff);
  printMap("Cuff", cuffDistribution, Cuff.toString);
};

let processFile = (inFileName: string): unit => {
  let fileContents = Node.Fs.readFileAsUtf8Sync(inFileName);

  let lines = Js.String.split("\n", fileContents) |> Js.Array.sliceFrom(1);

  let orders = Belt.Array.reduce(lines, [], lineReducer);

  printStatistics(orders);
};

let nodeArg = Belt.Array.get(Node.Process.argv, 0);
let progArg = Belt.Array.get(Node.Process.argv, 1);
let fileArg = Belt.Array.get(Node.Process.argv, 2);

switch (nodeArg, progArg, fileArg) {
| (_, _, Some(inFileName)) => processFile(inFileName)
| (Some(node), Some(prog), _) =>
  Js.log("Usage: " ++ node ++ " " ++ prog ++ " inputfile.csv")
| (_, _, _) =>
  Js.log("How did you get here without NodeJS or a program to run?")
};
