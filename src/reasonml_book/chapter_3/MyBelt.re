let myMap = (optValue: option('a), f: 'a => 'b): option('b) => {
  switch (optValue) {
  | Some(value) => Some(f(value))
  | None => None
  };
};

let myFlatMap = (optValue: option('a), f: 'a => option('b)): option('b) => {
  switch (optValue) {
  | Some(value) => f(value)
  | None => None
  };
};
