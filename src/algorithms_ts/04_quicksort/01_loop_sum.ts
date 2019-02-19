export const sum = (list: number[]): number => {
  let total: number = 0;
  for (let x: number = 0; x < list.length; x += 1) {
    total += list[x];
  }
  return total;
};

console.log('sum([1, 2, 3, 4]) :', sum([1, 2, 3, 4]));