const fs = require('fs')

fs.rename('lol.cpp', 'newDir/lol.py', err => {
    if(err) throw new Error(err)
})