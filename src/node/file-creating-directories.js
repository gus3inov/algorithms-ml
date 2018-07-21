const fs = require('fs')

if(!fs.exists('views')){
    fs.mkdir('views', err => {
        if(err) throw new Error(err)

        fs.writeFile('./views/new.html', 'this is new Directory and data', err => {
            if(err) throw new Error(err)


            console.log('its ok')
        })
    })
}