const http = require('http')
const fs = require('fs')

http.createServer((req, res) => {

    if(req.url === '/about'){
        fs.readFile('./src/data.html', 'UTF-8', (err, data) => {
            res.writeHead(200, {'Content-Type': 'text/html'})
            res.end(data)
        })
    }else{
        res.writeHead(404, {'Content-Type': 'text/plain'})
        res.end('404 Error Could not file you girl')
    }

}).listen(3333)

