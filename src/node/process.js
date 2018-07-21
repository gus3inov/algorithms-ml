process.stdout.write('Ask me smth: ')

process.stdin.on('data', data => {
    console.log(data.toString())

    process.exit()
})