interface IObservable<T> {
    listeners: Set;

    value: T;

    get(): T;

    set(newValue: T): void;

    subscribe(listener): void;

    unsubscribe(listener): void;

    notify(): void;
}

class Observable<T> implements IObservable<T> {
    public listeners = new Set();

    public value;

    constructor(value: T) {
        this.value = value;
    }

    public get get() {
        return this.value;
    }

    public set set(newValue) {
        if (newValue !== this.value) {
            this.notify();
        }
    }

    public subscribe(listener) {
        this.listeners.add(listener);
    }

    public unsubscribe(listener) {
        this.listeners.delete(listener);
    }

    public notify() {
        for (const listener of this.listeners) {
            listener();
        }
    }
}

const user = {
    fistName: new Observable("x"),
    lastName: new Observable("y"),
    age: new Observable(0)
};

const listener = () => console.log("first name");
user.firstName.subscribe(listener);
user.firstName.get();
user.firstName.set("new name");
user.fistName.unsubscribe(listener);
