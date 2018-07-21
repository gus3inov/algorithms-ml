const readline = require('src/node/readline')
const util = require('util')

const rl = readline.createInterface(process.stdin, process.stdout)

rl.question('What is your name: ', name => {

    rl.setPrompt(`${name} how old are you`)

    rl.prompt()

    rl.on('line', age => {
        if(age < 18){
            util.log(`${name.trim()}, ti ne voidesh because you are stupid eblan kotoromu ${age} let`)
        }else{
            util.log(`${name.trim()}, zbs, tebe ${age}`)
        }

        rl.close()
    })

})
