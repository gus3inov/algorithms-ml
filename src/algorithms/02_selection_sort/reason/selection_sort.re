/* type findSmallestIndex = array(int) => int;

let findSmallestIndex: findSmallestIndex =
  arr => {
    let smallestElement: ref(int) = ref(arr[0]);
    let smallestIndex: ref(int) = ref(0);

    (arr)) {
      if (arr[i] < smallestElement^) {
        smallestElement := arr[i];
        smallestIndex := i;
      };
    };

    smallestIndex^;
  };

type selectionSort = array(int) => array(int);

let selectionSort: selectionSort =
  arr => {
    let sortedArray = [||];

    for (i in 0 to Array.length(arr)) {
      let smallestIndex = findSmallestIndex(arr);
      Array.set(sortedArray, Array.sub(arr, smallestIndex, 1)[0]);
    };

    sortedArray;
  }; */