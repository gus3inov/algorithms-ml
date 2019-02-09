// Generated by BUCKLESCRIPT VERSION 4.0.14, PLEASE EDIT WITH CARE
'use strict';

var Belt_List = require("bs-platform/lib/js/belt_List.js");
var ShirtSize$Chapter5 = require("./ShirtSize.bs.js");

var orderList = /* :: */[
  /* tuple */[
    7,
    /* Medium */1
  ],
  /* :: */[
    /* tuple */[
      5,
      /* XLarge */[3]
    ],
    /* :: */[
      /* tuple */[
        4,
        /* Small */0
      ],
      /* :: */[
        /* tuple */[
          6,
          /* Large */2
        ],
        /* :: */[
          /* tuple */[
            8,
            /* Small */0
          ],
          /* :: */[
            /* tuple */[
              2,
              /* Large */2
            ],
            /* :: */[
              /* tuple */[
                9,
                /* Medium */1
              ],
              /* :: */[
                /* tuple */[
                  3,
                  /* XLarge */[2]
                ],
                /* [] */0
              ]
            ]
          ]
        ]
      ]
    ]
  ]
];

function onePrice(param) {
  return param[0] * ShirtSize$Chapter5.price(param[1]);
}

function isMedium(param) {
  return param[1] === /* Medium */1;
}

function addPrice(accumulator, orderItem) {
  return accumulator + onePrice(orderItem);
}

var priceList = Belt_List.map(orderList, onePrice);

var mediums = Belt_List.keep(orderList, isMedium);

var totalPrice = Belt_List.reduce(orderList, 0.0, addPrice);

var __x = Belt_List.map(orderList, onePrice);

var totalPrice2 = Belt_List.reduce(__x, 0.0, (function (acc, item) {
        return acc + item;
      }));

var __x$1 = Belt_List.map(orderList, onePrice);

var totalPrice3 = Belt_List.reduce(__x$1, 0.0, (function (prim, prim$1) {
        return prim + prim$1;
      }));

var __x$2 = Belt_List.keep(orderList, isMedium);

var __x$3 = Belt_List.map(__x$2, onePrice);

var mediumTotal = Belt_List.reduce(__x$3, 0.0, (function (prim, prim$1) {
        return prim + prim$1;
      }));

exports.orderList = orderList;
exports.onePrice = onePrice;
exports.isMedium = isMedium;
exports.addPrice = addPrice;
exports.priceList = priceList;
exports.mediums = mediums;
exports.totalPrice = totalPrice;
exports.totalPrice2 = totalPrice2;
exports.totalPrice3 = totalPrice3;
exports.mediumTotal = mediumTotal;
/* priceList Not a pure module */
