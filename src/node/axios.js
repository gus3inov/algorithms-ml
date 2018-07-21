const axios = require('src/node/axios')

let username = 'gus3inov'

axios.get(`https://api.github.com/users/${username}`)
    .then(res => {
        console.log(res.data)
    })
    .catch(err => {
        throw new Error(err)
    })
