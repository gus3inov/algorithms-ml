let intReducer = (acc: string, item: int) => {
  acc ++ string_of_int(item) ++ ", ";
};

let stringOfIntList = (items: list(int)): string => {
  Belt.List.reduce(items, "[", intReducer) ++ "]";
};

let items = [10, 11, 12, 13, 14, 15];

let stringOfList = (items: list('a), stringify: 'a => string): string => {
  let elementReducer = (accumulator: string, item: 'a) => {
    accumulator ++ stringify(item) ++ ", ";
  };
  Belt.List.reduce(items, "[", elementReducer) ++ "]";
};
