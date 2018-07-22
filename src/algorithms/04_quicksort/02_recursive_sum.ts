export const sum = (list: number[]): number => (list.length === 0) ? 0 : list[0] + sum(list.slice(1));

console.log('sum([4, 6, 12]) :', sum([4, 6, 12]));