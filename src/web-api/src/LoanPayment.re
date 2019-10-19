open Payment;

module D = Webapi.Dom;
module Document = Webapi.Dom.Document;
module Elem = Webapi.Dom.Element;

let principalInput = Document.getElementById("principal", D.document);
let aprInput = Document.getElementById("apr", D.document);
let yearsInput = Document.getElementById("years", D.document);
let paymentElem = Document.getElementById("payment", D.document);

let toInt = (s: string): option(int) =>
  switch (int_of_string(s)) {
  | result => Some(result)
  | exception (Failure("int_of_string")) => None
};

let toFloat = (s: string): option(float) =>
  switch (float_of_string(s)) {
  | result => Some(result)
  | exception (Failure("float_of_string")) => None
};

let getStringValue = (id: string): option(string) =>
  Document.getElementById(id, D.document)
  ->Belt.Option.map(Elem.unsafeAsHtmlElement)
  ->Belt.Option.map(D.HtmlElement.value);

let getIntValue = (id: string): option(int) => getStringValue(id)->Belt.Option.flatMap(toInt);

let getFloatValue = (id: string): option(float) => getStringValue(id)->Belt.Option.flatMap(toFloat);

let calculate = (_: Dom.event): unit => {
  let principalValue = getFloatValue("principal");
  let aprValue = getFloatValue("apr");
  let yearsValue = getIntValue("years");

  let payment =
    switch (principalValue, aprValue, yearsValue) {
    | (Some(principal), Some(apr), Some(years)) =>
      Some(Shirts.Payment.payment(~principal, ~apr, ~years))
    | (_, _, _) => None
    };

  let paymentString =
    switch (payment) {
    | Some(p) => Js.Float.toFixedWithPrecision(p, ~digits=2)
    | None => ""
    };

  let _ =
    paymentElem->Belt.Option.map(__x =>
      Elem.setInnerText(__x, paymentString)
    );

  ();
};

let addEvent = (input: option('a), f: Dom.event => unit): unit =>
  switch (input) {
  | Some(element) =>
    Webapi.Dom.EventTarget.addEventListener(
      "input",
      f,
      Elem.asEventTarget(element),
    )
  | None => ()
};

addEvent(principalInput, calculate);

addEvent(aprInput, calculate);

addEvent(yearsInput, calculate);
