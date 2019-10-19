let items = [10, 11, 12, 13, 14, 15, 16];

let sqrtPlusOne = x => {
  sqrt(float_of_int(x) +. 1.0);
};
let roots = Belt.List.makeBy(5, sqrtPlusOne);

let taken3 = Belt.List.take(items, 3);
let dropped3 = Belt.List.drop(items, 3);
let badTake = Belt.List.take(items, 10);

let result = Belt.List.splitAt(items, 3);

switch (result) {
| Some((firstPart, lastPart)) =>
  Js.log(firstPart);
  Js.log(lastPart);
| None => Js.log("None")
};

let optElement = Belt.List.get(items, 3); 
let badOptElement = Belt.List.get(items, 10);
let element = Belt.List.getExn(items, 3);
let badElement = Belt.List.getExn(items, 10);