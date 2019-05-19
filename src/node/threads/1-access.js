const threads = require('worker_threads');

const { buffer } = threads.workerData;
const array = new Int32Array(buffer);
array[0] = 322;
threads.parentPort.postMessage({ name: 'display' });