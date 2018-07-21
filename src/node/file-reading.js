const fs = require('fs');

fs.readdir('./src', (err, content) => {
    if(err) throw new Error(err)

    console.log(content)
})

fs.readFile('global.html', 'UTF-8', (err, content) => {
    if(err) throw new Error(err)

    console.log(content)
})