class Invoker {
    constructor(command) {
        this.command = command;
    }

    execute() {
        this.command.execute();
    }
}

class Animal {
    constructor() {
        this.state = false;
        this.actions = [];
    }

    run() {
        this.state = true;
        this.actions.push("run");
    }

    stay() {
        this.state = false;
        this.actions.push("stay");
    }

    undo() {
        this.actions.slice(1);
    }
}

class RunRecieve {
    constructor(animal) {
        this.animal = animal;
    }

    execute() {
        this.animal.run();
    }
}

class StayRecieve {
    constructor(animal) {
        this.animal = animal;
    }

    execute() {
        this.animal.stay();
    }
}

const animal = new Animal();

const runRecieve = new RunRecieve(animal);

const stayRecieve = new StayRecieve(animal);

const invokerRun = new Invoker(runRecieve);

const invokerStay = new Invoker(stayRecieve);

invokerRun.execute();

invokerStay.execute();
