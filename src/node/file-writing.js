const fs = require('fs')

const convertToFormat = data =>
    data.splice(1).map(i => ({
        id: i.B,
        type: i.A,
        geometry: {
            type: i.C,
            coordinates: [i.D, i.E]
        },
        properties: {
            balloonContentHeader: i.F,
            balloonContentBody: i.G,
        }
    }));

fs.readFile('./src/node/data.json', 'utf8', (err, data) => {
    if (err) {
        console.log(err);
    } else {
        const json = JSON.stringify(convertToFormat(JSON.parse(data)));
        fs.writeFileSync('nameOutputJson.json', json, 'utf8');
    }
});