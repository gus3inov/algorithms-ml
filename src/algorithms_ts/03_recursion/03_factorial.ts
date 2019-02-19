const fact = (num: number): number => num === 0 ? 1 : num * fact(num -1);

console.log(fact(10));

export default fact;
