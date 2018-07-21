const execute = require('child_process').exec;

execute('node src/events.js', (err, stdout) => {
    if(err) console.error(err);

    console.log(stdout)
});