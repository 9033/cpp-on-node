const os = require('os');
console.assert(os.arch() === 'x64', 'x64')
console.assert(os.platform() === 'linux', 'linux')

const ffi = require('ffi-napi');

const t = ffi.Library('./shared', {
  'add': ['int', ['int', 'int']],
})

const r = t.add(5,2)

console.log(r);
