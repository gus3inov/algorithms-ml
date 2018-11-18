let binary_search = (list: array(int), item: int) => {
    let low: ref(int) = ref(0);
    let high: ref(int) = ref(Array.length(list) - 1);

    while(low^ <= high^) {
        let midFloat = float_of_int(((low^ + high^) / 2));
        let mid = Js.Math.floor(midFloat);
        let guess = list[mid];

        if(guess == item) {
            mid;
        } else if(guess > item) {
            high := mid - 1;

            high^;
        } else {
            low := mid + 1;

            low^;
        }
    }

    None;
}