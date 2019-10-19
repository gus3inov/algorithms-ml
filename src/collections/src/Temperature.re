type temperature = (float, int);

let temperaturesData = [
    (12.5, 30),
    (13.7, 35),
    (13.2, 32),
    (13.7, 35)
];

let calculateTemperature = ((t, rh): temperature): float => {
    t -. ((100.0 -. float_of_int(rh) /. 5.0));
}

let result = Belt.List.map(temperaturesData, calculateTemperature);
Js.log(result);