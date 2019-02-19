/* let binary_search = (
  list: array(int),
  item: int
) => {
  let low: ref(int) = ref(0);
  let high: ref(int) = ref(Array.length(list) - 1);

  while (low^ <= high^) {
    let midFloat = float_of_int((low^ + high^) / 2);
    let mid = Js.Math.floor(midFloat);
    let guess = Array.get(list, mid);

    switch(guess === item, guess > item) {
    | (true, false) => mid
    | (false, false) => low := mid + 1
    | (false, true) => high := mid - 1
    | _ => None;
    };
  };

  None;
};

let testArray: array(int) = [|1, 4, 5, 12, 231, 2, 3, 4|];

Js.log(binary_search(testArray, 2)); */
