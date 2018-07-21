console.clear();

console.time('binary_search');

export const binary_search = <T>(list: Array[T], item: T): T => {
    let low: T = 0,
        high: T = list.length - 1;

    while(low <= high) {
        let mid: T = Math.floor(((low + high) / 2)),
            guess: T = list[mid];
        console.log('mid ----', mid);
        console.log('guess ----', guess);

        if (guess === item) {
            console.log('end');
            return mid;
        } else if (guess > item) {
            console.log(`more then ${item}`);
            high = mid - 1;
        } else {
            console.log(`less then ${item}`);
            low = mid + 1;
        }
    }

    return null;
};

export const myList: Array[number] = [1, 3, 4, 5, 6, 12];

console.log(binary_search<number>(myList, 5));

console.timeEnd('binary_search');
