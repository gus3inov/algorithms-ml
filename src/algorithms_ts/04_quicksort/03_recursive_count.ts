export const count = (list: number[]): number => (list.length === 0) ? 0 : 1 + count(list.slice(1)); 

console.log('count([4, 6, 12]) :', count([4, 6, 12, 2, 9]));