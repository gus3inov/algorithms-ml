const findSmallestIndex = <A, T>(array: A): T => {
    let smallestElement: T = array[0],
        smallestIndex: T = 0;

    for(let i: T = 1; i < array.length; i++) {
        console.log(array[i], smallestElement);
        if(array[i] < smallestElement) {
            smallestElement = array[i];
            smallestIndex = i;
        }
    }

    return smallestIndex;
};

const selectionSort = <A>(array: A): A => {
    const sortedArray = [];

    for(let i: number = 0; i < array.length; i++) {
        const smallestIndex = findSmallestIndex(array);
        sortedArray.push(array.splice(smallestIndex, 1)[0]);
    }

    return sortedArray;
};

console.log(selectionSort<Array>([8, 5, 2, 1, 4, 10, 16]));
