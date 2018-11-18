const fs = require('fs');
const http = require('http');

// fs.readdir('./src', (err, content) => {
//     if(err) throw new Error(err)
//
//     console.log(content)
// })
//
// fs.readFile('global.html', 'UTF-8', (err, content) => {
//     if(err) throw new Error(err)
//
//     console.log(content)
// })

http.createServer((req, res) => {
    const file = fs.createReadStream('./src/grokking_algorithms/09_dynamic_programming/Haskell/01_knapsack_dynamic_prog.hs', { start: 90, end: 99 })

    file.open('open', (err, res) => {
        console.log(res);
        file.pipe(res);
    });

    file.on('error', (err, res) => {
        console.log(res);
        file.pipe(res);
    });
}).listen(8000, '127.0.0.1');
