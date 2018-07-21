const request = require('request');
const through2 = require('through2');

const toUpperCase = through2((data, enc, cb) => {
    cb(null, new Buffer(data.toString().toUpperCase()));
});

const dashBetweenWords = through2((data, enc, cb) => {
    cb(null, new Buffer(data.toString().split(' ').join('-')));
});

request('https://fettblog.eu')
    .pipe(dashBetweenWords)
    .pipe(toUpperCase)
    .pipe(data => {
        console.log(data)
    });