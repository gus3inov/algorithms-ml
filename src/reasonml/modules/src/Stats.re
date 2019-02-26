open Shirts;

let map2 = (optX, optY, f) => {
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
        size: Size.Small,
        sleeve: Sleeve.Short,
        color: Color.White,
        pattern: Pattern.Solid,
        cuff: Cuff.Button,
        collar: Collar.Button,
      });

    let orderRecord =
      map2(initial, optInt(items[0]), (result, n) =>
        {...result, quantity: n}
      )
      ->map2(Size.fromString(items[1]), (result, size) => {...result, size})
      ->map2(Sleeve.fromString(items[2]), (result, sleeve) =>
          {...result, sleeve}
        )
      ->map2(Color.fromString(items[3]), (result, color) =>
          {...result, color}
        )
      ->map2(Pattern.fromString(items[4]), (result, pattern) =>
          {...result, pattern}
        )
      ->map2(Cuff.fromString(items[5]), (result, cuff) => {...result, cuff})
      ->map2(Collar.fromString(items[6]), (result, collar) =>
          {...result, collar}
        );

    switch (orderRecord) {
    | Some(result) => [result, ...acc]
    | None => acc
    };
  };
};

let printStatistics = (orders: list(order)): unit => {
  let colorDistribution =
    Belt.List.reduce(
      orders,
      Belt.Map.make(~id=(module ColorComparator)),
      (acc, item) => {
        let n = Belt.Map.getWithDefault(acc, item.color, 0);
        Belt.Map.set(acc, item.color, n + item.quantity);
      },
    );

  Js.log2("Color", "Quanity");
  Belt.Map.forEach(colorDistribution, (key, value) =>
    Js.log2(Color.toString(key), value)
  );
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
