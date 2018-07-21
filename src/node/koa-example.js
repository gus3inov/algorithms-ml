const Koa = require('koa');
const app = new Koa();

// x-response-time

app.use(async (ctx, next) => {
    const start = Date.now();
    console.log('1 before next')
    await next();
    console.log('1 after next')
    const ms = Date.now() - start;
});

// logger

app.use(async (ctx, next) => {
    const start = Date.now();
    console.log('2 before next')
    await next();
    console.log('2 after next')
    const ms = Date.now() - start;
});

// response

app.use(async ctx => {
    ctx.body = 'Hello World';
});

app.listen(3000);