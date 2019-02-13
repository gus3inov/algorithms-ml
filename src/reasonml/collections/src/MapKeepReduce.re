let orderList = [
  (7, ShirtSize.Medium),
  (5, ShirtSize.XLarge(3)),
  (4, ShirtSize.Small),
  (6, ShirtSize.Large),
  (8, ShirtSize.Small),
  (2, ShirtSize.Large),
  (9, ShirtSize.Medium),
  (3, ShirtSize.XLarge(2)),
];

let onePrice = ((qty: int, size: ShirtSize.t)): float => {
  float_of_int(qty) *. ShirtSize.price(size);
};

let isMedium = ((_, size)): bool => {
  size === ShirtSize.Medium;
};

let addPrice = (accumulator, orderItem) => {
  accumulator +. onePrice(orderItem);
};

let priceList = Belt.List.map(orderList, onePrice);
let mediums = Belt.List.keep(orderList, isMedium);
let totalPrice = Belt.List.reduce(orderList, 0.0, addPrice);

let totalPrice2 =
  Belt.List.map(orderList, onePrice)
  ->Belt.List.reduce(_, 0.0, (acc, item) => acc +. item);

let totalPrice3 =
  Belt.List.map(orderList, onePrice)
  ->Belt.List.reduce(_, 0.0, (+.));

let mediumTotal =
    Belt.List.keep(orderList, isMedium)
    -> Belt.List.map(_, onePrice)
    -> Belt.List.reduce(_, 0.0, (+.));

    