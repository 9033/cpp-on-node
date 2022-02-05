const os = require('os');
console.assert(os.arch() === 'x64', 'x64')
console.assert(os.platform() === 'linux', 'linux')

const ffi = require('ffi-napi');
const ref = require('ref-napi')
const ArrayType = require('ref-array-napi')
const DoubleArray = ArrayType(ref.types.double)

const t = ffi.Library('./shared', {
  // 'add': ['int', ['int', 'int']],
  'adds': ['double', ['double *', 'int']],// or 'adds': ['double', [DoubleArray, 'int']],
})

const numbers = Array(50000)
numbers.fill(0)
for(let i in numbers)numbers[i] = Math.random()

if(numbers.length <= 10)console.log(numbers);

function adds(numbers){
  let result = 0;
  for(let i = 0;i<numbers.length;i++){
    result += numbers[i];
  }
  return result;
}

console.time('node')
const r = adds(numbers)
console.timeEnd('node')
console.log(r);

// console.time('node-reduce')
// const r4 = numbers.reduce((p, c)=>(p + c), 0)
// console.timeEnd('node-reduce')
// console.log(r4);

console.time('ffi')
// const r2 = t.adds(numbers, numbers.length) // 'adds': ['double', [DoubleArray, 'int']],
const n = DoubleArray(numbers) // too slow to convert Number to double
const r2 = t.adds(n.buffer, numbers.length)
console.timeEnd('ffi')
console.log(r2);

console.time('ffi-2')
const buf = Float64Array.from(numbers)
const r3 = t.adds(Buffer.from(buf.buffer), numbers.length)
console.timeEnd('ffi-2')
console.log(r3);

// console.time('node-typed')
// const buf2 = Float64Array.from(numbers)
// const r5 = adds(buf2, numbers.length)
// console.timeEnd('node-typed')
// console.log(r5);

// console.time('node-typed-reduce')
// const buf3 = Float64Array.from(numbers)
// const r6 = buf3.reduce((p, c)=>(p + c), 0)
// console.timeEnd('node-typed-reduce')
// console.log(r6);

/*
const p1 = async () => {
  console.time('node-promise')
  const n1 = numbers.slice(0, parseInt(numbers.length / 2))
  const n2 = numbers.slice(parseInt(numbers.length / 2), numbers.length)
  const a = async n=>(await adds(n))
  const k = await Promise.all([a(n1), a(n2)])
  const r = k[0]+k[1]
  console.timeEnd('node-promise')
  console.log(r);
}
p1()
*/

