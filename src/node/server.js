const http = require('http')
const url = require('url')

const server = http.Server((req, res) => {
    const urlParsed = url.parse(req.url, true)
    
    if(urlParsed.pathname == '/echo' && urlParsed.query.message) {
        res.end(urlParsed.query.message)
    }

    res.statusCode = 404
    res.end("Page not found")
})

server.listen(1337, '127.0.0.1')