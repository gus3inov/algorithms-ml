console.clear();
console.time('binary_search');

export const binary_search = <T>(list: Array<T>, item: T): T => {
    let low = 0,
        high = list.length - 1;

    while(low <= high) {
        let mid = Math.floor(((low + high) / 2)),
            guess = list[mid];

        if (guess === item) {
            return mid;
        } else if (guess > item) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return null;
};

export const myList: Array<number> = [1, 3, 4, 5, 6, 12];

console.log(binary_search<number>(myList, 5));
console.timeEnd('binary_search');
