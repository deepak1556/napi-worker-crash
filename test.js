const test = require('./build/Release/test.node')

for (let i = 0; i < 100; i++) {
   test.startAsyncWork((err) => {
     console.log(err)
   })
}