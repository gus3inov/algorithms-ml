const fs = require('fs')

fs.writeFile('data.html', 'Fuck you bitch !', 'UTF-8', err => {
    if(err) throw new Error(err)

    console.log('Thew file has changed or have been saved')
})

fs.appendFile('./src/data.html', 'data.html fasd fasdfa sdf \n', 'UTF-8', err => {
    if(err) throw new Error(err)

    console.log('Thew file has changed or have been saved')
})