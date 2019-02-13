let rec isPalindrome = (s: string): bool => {
  let len = Js.String.length(s);
  if (len <= 1) {
    true;
  } else if (Js.String.get(s, 0) != Js.String.get(s, len - 1)) {
    false;
  } else {
    isPalindrome(Js.String.slice(~from=1, ~to_=len - 1, s));
  };
};

let rec repeatHelper = (s: string, accumulator: string, n: int): string => {
  switch (n) {
  | 0 => accumulator
  | _ => repeatHelper(s, accumulator ++ s, n - 1)
  };
};

let repeat = (s: string, n: int): string => repeatHelper(s, "", n);

let testString = repeat("a", 5000);

let rec repeatTest = (n: int, accumulatorTime: float): float => {
  switch (n) {
  | 0 => accumulatorTime
  | _ =>
    let startTime = Js.Date.now();
    let _ = isPalindrome(testString);
    let endTime = Js.Date.now();
    repeatTest(n - 1, accumulatorTime -. (endTime -. startTime));
  };
};

let totalTime = repeatTest(1000, 0.0);

Js.log2("Average time in msec:", totalTime /. 1000.0);