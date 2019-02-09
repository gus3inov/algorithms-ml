module D = Webapi.Dom;
module Doc = Webapi.Dom.Document;
module Elem = Webapi.Dom.Element;

type order = (int, ShirtSize.t);
type resultOrder = Belt.Result.t(order, string);

let commaSplit = (s: string): array(string) => {
  let pattern = [%re "/\\s*,\\s*/"];
  Js.String.splitByRe(pattern, s);
};

let toOrder = (s: string): resultOrder => {
  let pattern = [%re "/(\\d{1,4})\\s*@?\\s*(S|M|X{0,4}L)/"];
  let results = Js.String.match(pattern, Js.String.toUpperCase(s));
  switch (results) {
  | Some(arr) =>
    switch (ShirtSize.fromString(arr[2])) {
    | Some(size) => Belt.Result.Ok((int_of_string(arr[1]), size))
    | None => Belt.Result.Error(s)
    }
  | None => Error(s)
  };
};

let calculateTotalShirts = (orders: array(resultOrder)): int => {
  let adder = (accumulator, optOrder) => {
    switch (optOrder) {
    | Belt.Result.Ok((n, _)) => accumulator + n
    | _ => accumulator
    };
  };
  Belt.Array.reduce(orders, 0, adder);
};

let str = "3M, 5 @ S, 7 BAD, 9 XXL";

let nShirts =
  commaSplit(str)->Belt.Array.map(_, toOrder)->calculateTotalShirts(_);

let orderPrice = ((n, size): order): float => {
  float_of_int(n) *. ShirtSize.price(size);
};

let calculateTotals = (orders: array(resultOrder)): (int, float) => {
  let adder = (accumulator, optOrder) => {
    let (accShirts, accPrice) = accumulator;
    switch (optOrder) {
    | Belt.Result.Ok((n, size)) => (
        accShirts + n,
        accPrice +. orderPrice((n, size)),
      )
    | _ => accumulator
    };
  };
  Belt.Array.reduce(orders, (0, 0.0), adder);
};

let createRow = (anOrder: resultOrder): string => {
  switch (anOrder) {
  | Belt.Result.Ok((n, size)) =>
    let total =
      Js.Float.toFixedWithPrecision(orderPrice((n, size)), ~digits=2);
    let sizeStr = ShirtSize.toString(size);
    {j|<tr><td class="right">$n</td>
    <td class="center">$sizeStr</td>
    <td class="right">\$$total</td></tr>\n|j};
  | Belt.Result.Error(s) => {j|<tr><td colspan="3">Bad input $s</td></tr>\n|j}
  };
};

let createTable = (orderArray: array(resultOrder)): string => {
  let tableBody =
    Belt.Array.reduce(orderArray, "", (accumulator, item) =>
      accumulator ++ createRow(item)
    );
  {j|
    <table>
    <thead>
    <tr><th>Quantity</th><th>Size</th><th>Price</th>
    </thead>
    <tbody>
    |j}
  ++ tableBody
  ++ {j|
    </tbody>
    </table>
    |j};
};

let getValue = (element: option(Elem.t)): option(string) => {
  element
  ->Belt.Option.map(_, Elem.unsafeAsHtmlElement)
  ->Belt.Option.map(_, D.HtmlElement.value);
};

let calculate = (_: Dom.event): unit => {
  switch (getValue(Doc.getElementById("orders", D.document))) {
  | Some(str) =>
    let orderArray =
      commaSplit(str)
      ->Belt.Array.keep(_, item => item !== "")
      ->Belt.Array.map(_, toOrder);
    let (nShirts, grandTotal) = calculateTotals(orderArray);
    let priceString = Js.Float.toFixedWithPrecision(grandTotal, ~digits=2);
    let _ =
      Doc.getElementById("table", D.document)
      ->Belt.Option.map(__x =>
          Elem.setInnerHTML(__x, createTable(orderArray))
        );
    let _ =
      Doc.getElementById("totalShirts", D.document)
      ->Belt.Option.map(__x =>
          Elem.setInnerText(__x, string_of_int(nShirts))
        );
    let _ =
      Doc.getElementById("totalPrice", D.document)
      ->Belt.Option.map(__x => Elem.setInnerText(__x, priceString));
    ();
  | None => ()
  };
};

let calcButton = Doc.getElementById("calculate", D.document);
switch (calcButton) {
| Some(element) =>
  D.EventTarget.addEventListener(
    "click",
    calculate,
    D.Element.asEventTarget(element),
  )
| None => ()
};
