let data = [2, 6, 5, 7, 42, 20, 3];
let isEven = (n) => { (n mod 2) == 0 };

let optToInt = (a: option(int)): int => {
    switch (a) {
    | Some(value) => value
    | None => -1;
    };
}

let takeWhile = (items: list(int), f: 'a => bool): list(int) => {
    let rec helper = (position: int, accumulator: list(int)): list(int) => {
        if (position < Belt.List.size(items)) {
            let value = optToInt(Belt.List.get(items, position));
            switch (!f(value)) {
                | true => helper(position + 1, Belt.List.concat(accumulator, [value]))
                | false => helper(position + 1, accumulator)
            };
        } else {
            Js.log2(position, "accumulator");
            accumulator;
        }
    }
    helper(0, []);
}

let taken = takeWhile(data, isEven);
Js.log(taken);