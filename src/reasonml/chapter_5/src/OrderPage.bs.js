// Generated by BUCKLESCRIPT VERSION 4.0.14, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Belt_Array = require("bs-platform/lib/js/belt_Array.js");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Caml_format = require("bs-platform/lib/js/caml_format.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var ShirtSize$Chapter5 = require("./ShirtSize.bs.js");

function commaSplit(s) {
  var pattern = (/\s*,\s*/);
  return s.split(pattern);
}

function toOrder(s) {
  var pattern = (/(\d{1,4})\s*@?\s*(S|M|X{0,4}L)/);
  var results = s.toUpperCase().match(pattern);
  if (results !== null) {
    var match = ShirtSize$Chapter5.fromString(Caml_array.caml_array_get(results, 2));
    if (match !== undefined) {
      return /* Ok */Block.__(0, [/* tuple */[
                  Caml_format.caml_int_of_string(Caml_array.caml_array_get(results, 1)),
                  match
                ]]);
    } else {
      return /* Error */Block.__(1, [s]);
    }
  } else {
    return /* Error */Block.__(1, [s]);
  }
}

function calculateTotalShirts(orders) {
  var adder = function (accumulator, optOrder) {
    if (optOrder.tag) {
      return accumulator;
    } else {
      return accumulator + optOrder[0][0] | 0;
    }
  };
  return Belt_Array.reduce(orders, 0, adder);
}

var str = "3M, 5 @ S, 7 BAD, 9 XXL";

var __x = commaSplit(str);

var nShirts = calculateTotalShirts(Belt_Array.map(__x, toOrder));

function orderPrice(param) {
  return param[0] * ShirtSize$Chapter5.price(param[1]);
}

function calculateTotals(orders) {
  var adder = function (accumulator, optOrder) {
    if (optOrder.tag) {
      return accumulator;
    } else {
      var match = optOrder[0];
      var n = match[0];
      return /* tuple */[
              accumulator[0] + n | 0,
              accumulator[1] + orderPrice(/* tuple */[
                    n,
                    match[1]
                  ])
            ];
    }
  };
  return Belt_Array.reduce(orders, /* tuple */[
              0,
              0.0
            ], adder);
}

function createRow(anOrder) {
  if (anOrder.tag) {
    return "<tr><td colspan=\"3\">Bad input " + (String(anOrder[0]) + "</td></tr>\n");
  } else {
    var match = anOrder[0];
    var size = match[1];
    var n = match[0];
    var total = orderPrice(/* tuple */[
            n,
            size
          ]).toFixed(2);
    var sizeStr = ShirtSize$Chapter5.toString(size);
    return "<tr><td class=\"right\">" + (String(n) + ("</td>\n    <td class=\"center\">" + (String(sizeStr) + ("</td>\n    <td class=\"right\">\$" + (String(total) + "</td></tr>\n")))));
  }
}

function createTable(orderArray) {
  var tableBody = Belt_Array.reduce(orderArray, "", (function (accumulator, item) {
          return accumulator + createRow(item);
        }));
  return "\n    <table>\n    <thead>\n    <tr><th>Quantity</th><th>Size</th><th>Price</th>\n    </thead>\n    <tbody>\n    " + (tableBody + "\n    </tbody>\n    </table>\n    ");
}

function getValue(element) {
  var __x = Belt_Option.map(element, (function (prim) {
          return prim;
        }));
  return Belt_Option.map(__x, (function (prim) {
                return prim.value;
              }));
}

function calculate(param) {
  var match = getValue(Caml_option.nullable_to_opt(document.getElementById("orders")));
  if (match !== undefined) {
    var __x = commaSplit(match);
    var __x$1 = Belt_Array.keep(__x, (function (item) {
            return item !== "";
          }));
    var orderArray = Belt_Array.map(__x$1, toOrder);
    var match$1 = calculateTotals(orderArray);
    var nShirts = match$1[0];
    var priceString = match$1[1].toFixed(2);
    Belt_Option.map(Caml_option.nullable_to_opt(document.getElementById("table")), (function (__x) {
            __x.innerHTML = createTable(orderArray);
            return /* () */0;
          }));
    Belt_Option.map(Caml_option.nullable_to_opt(document.getElementById("totalShirts")), (function (__x) {
            __x.innerText = String(nShirts);
            return /* () */0;
          }));
    Belt_Option.map(Caml_option.nullable_to_opt(document.getElementById("totalPrice")), (function (__x) {
            __x.innerText = priceString;
            return /* () */0;
          }));
    return /* () */0;
  } else {
    return /* () */0;
  }
}

var calcButton = document.getElementById("calculate");

if (!(calcButton == null)) {
  calcButton.addEventListener("click", calculate);
}

var D = 0;

var Doc = 0;

var Elem = 0;

var calcButton$1 = (calcButton == null) ? undefined : Caml_option.some(calcButton);

exports.D = D;
exports.Doc = Doc;
exports.Elem = Elem;
exports.commaSplit = commaSplit;
exports.toOrder = toOrder;
exports.calculateTotalShirts = calculateTotalShirts;
exports.str = str;
exports.nShirts = nShirts;
exports.orderPrice = orderPrice;
exports.calculateTotals = calculateTotals;
exports.createRow = createRow;
exports.createTable = createTable;
exports.getValue = getValue;
exports.calculate = calculate;
exports.calcButton = calcButton$1;
/* nShirts Not a pure module */