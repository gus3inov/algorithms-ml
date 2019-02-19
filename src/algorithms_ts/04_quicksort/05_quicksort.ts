export const quickSort = (array: number[]): number[] => {
    if(array.length < 2) {
        return array;
    }
    const pivot: number = array[0];
    const keysAreLessPivot: number[] = array.slice(1).filter(key => key <= pivot);
    const keysAreMorePivot: number[] = array.slice(1).filter(key => key > pivot);

    return [...quickSort(keysAreLessPivot), pivot, ...quickSort(keysAreMorePivot)];
};

console.log(quickSort([10, 5, 12, 3]));
