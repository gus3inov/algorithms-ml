const countdown = (i: number): number => {
    console.log(i);
    if(i <= 0) {
        return null;
    }
    countdown(i - 1);
    return null;
};

countdown<number>(5);

export default countdown;
