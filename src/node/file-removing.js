const fs = require('fs')

fs.unlink('./views/new.html', err => {
    if(err) throw new Error(err)

    fs.rmdirSync('./views')
})