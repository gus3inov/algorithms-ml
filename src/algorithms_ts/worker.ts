function average(numbers) {
    var len = numbers.length,
        sum = 0,
        i;

    if (len === 0) {
        return 0;
    }

    for (i = 0; i < len; i++) {
        sum += numbers[i];
    }

    return sum / len;
}

self.addEventListener('message', function(e) {
    var data = e.data;
    switch (data.cmd) {
        case 'average':
            console.log(data.data)
            var result = average(data.data);
            self.postMessage(result);
            break;
        default:
            self.postMessage('Unknown command');
    }
}, false);

var bc = new BroadcastChannel('test_channel');

// Пример отправки сообщения
bc.postMessage('This is a test message.');

// Пример простого обработчика событий, который
// выводит сообщения в консоль
bc.onmessage = function (e) {
    console.log(e.data);
}

// Отключение от канала
bc.close()