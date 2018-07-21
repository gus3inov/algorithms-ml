const events = require('src/node/events')

const ee = new events.EventEmitter()

ee.on('newEvent', message => {

    console.log(`Message: ${message}`)

})

ee.emit('newEvent', 'LOl');
