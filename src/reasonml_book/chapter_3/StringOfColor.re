type colorSpec =
  | White
  | Black
  | Gray(float)
  | RGB(int, int, int)

let color1 = White;
let color2 = Black;
let color3 = Gray(0.50); 
let color4 = RGB(255, 255, 255);


let stringOfColorSpec = (cspec: colorSpec) : string => {
    switch (cspec) {
    | White => "#ffffff"
    | Black => "#000000"
    | Gray(opacity) => {j| rgb(32, 23, $opacity) |j}
    | RGB(red, green, blue) => {j| rgb($red, $green, $blue) |j}
    };
};