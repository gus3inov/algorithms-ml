module Size = {
  type t =
    | XSmall(int)
    | Small
    | Medium
    | Large
    | XLarge(int);

  let toString = (size: t): string => {
    switch (size) {
    | XSmall(n) => String.make(n, 'X') ++ "S"
    | Small => "S"
    | Medium => "M"
    | Large => "L"
    | XLarge(n) => String.make(n, 'X') ++ "L"
    };
  };

  let fromString = (s: string): option(t) => {
    switch (Js.String.toUpperCase(s)) {
    | "S" => Some(Small)
    | "M" => Some(Medium)
    | "L" => Some(Large)
    | s when Js.Re.test(s, [%re "/^X+S$/"]) =>
      Some(XSmall(String.length(s) - 1))
    | s when Js.Re.test(s, [%re "/^X+L$/"]) =>
      Some(XLarge(String.length(s) - 1))
    | _ => None
    };
  };
};

module SizeComparator =
  Belt.Id.MakeComparable({
    type t = Size.t;
    let cmp = compare;
  });

module Cuff = {
  type t =
    | Button
    | French
    | NoCuff;

  let toString = (cuff: t): string => {
    switch (cuff) {
    | Button => "button"
    | French => "french"
    | NoCuff => "none"
    };
  };

  let fromString = (s: string): option(t) => {
    switch (Js.String.toLowerCase(s)) {
    | "button" => Some(Button)
    | "french" => Some(French)
    | ""
    | "none"
    | "nocuff" => Some(NoCuff)
    | _ => None
    };
  };
};

module CuffComparator =
  Belt.Id.MakeComparable({
    type t = Cuff.t;
    let cmp = compare;
  });

module Sleeve = {
  type t =
    | Short
    | Long
    | XLong;

  let toString = (sleeve: t): string => {
    switch (sleeve) {
    | Short => "short"
    | Long => "long"
    | XLong => "xlong"
    };
  };

  let fromString = (s: string): option(t) => {
    switch (Js.String.toLowerCase(s)) {
    | "short" => Some(Short)
    | "long" => Some(Long)
    | "xlong" => Some(XLong)
    | _ => None
    };
  };
};

module SleeveComparator =
  Belt.Id.MakeComparable({
    type t = Sleeve.t;
    let cmp = compare;
  });

module Color = {
  type t =
    | White
    | Blue
    | Red
    | Green
    | Brown;

  let toString = (color: t): string => {
    switch (color) {
    | White => "white"
    | Blue => "blue"
    | Red => "red"
    | Green => "green"
    | Brown => "brown"
    };
  };

  let fromString = (s: string): option(t) => {
    switch (Js.String.toLowerCase(s)) {
    | "white" => Some(White)
    | "blue" => Some(Blue)
    | "red" => Some(Red)
    | "green" => Some(Green)
    | "brown" => Some(Brown)
    | _ => None
    };
  };
};

module ColorComparator =
  Belt.Id.MakeComparable({
    type t = Color.t;
    let cmp = compare;
  });

module Pattern = {
  type t =
    | Solid
    | Pinstripe
    | Check;

  let toString = (pattern: t): string => {
    switch (pattern) {
    | Solid => "solid"
    | Pinstripe => "pinstripe"
    | Check => "check"
    };
  };

  let fromString = (s: string): option(t) => {
    switch (Js.String.toLowerCase(s)) {
    | "solid" => Some(Solid)
    | "pinstripe" => Some(Pinstripe)
    | "check" => Some(Check)
    | _ => None
    };
  };
};

module PatternComparator =
  Belt.Id.MakeComparable({
    type t = Pattern.t;
    let cmp = compare;
  });

module Collar = {
  type t =
    | Button
    | Straight
    | Spread;

  let toString = (collar: t): string => {
    switch (collar) {
    | Button => "button"
    | Straight => "straight"
    | Spread => "spread"
    };
  };

  let fromString = (s: string): option(t) => {
    switch (Js.String.toLowerCase(s)) {
    | "button" => Some(Button)
    | "straight" => Some(Straight)
    | "spread" => Some(Spread)
    | _ => None
    };
  };
};

module CollarComparator =
  Belt.Id.MakeComparable({
    type t = Collar.t;
    let cmp = compare;
  });

type order = {
  quantity: int,
  size: Size.t,
  sleeve: Sleeve.t,
  color: Color.t,
  pattern: Pattern.t,
  cuff: Cuff.t,
  collar: Collar.t,
};

let myOrder = {
  quantity: 1,
  size: XLarge(1),
  sleeve: Long,
  color: Blue,
  pattern: Solid,
  cuff: Button,
  collar: Button,
};
