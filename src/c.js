const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin
});

let i = 0;
const result = [];
rl.on('line', (line) => {
    if (i >= 1 && result[result.length - 1] !== line) {
        result.push(line)
        process.stdout.write(`new line - ${line}\n`)
    }
    i++;
    if (i === 10) {
        rl.close();
    }
})