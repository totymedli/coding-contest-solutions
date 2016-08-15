var BigNumber = require('bignumber.js');

function processData(input) {
    var rows = input.split('\n');
    var n = rows[0];
    var sum = new BigNumber(0);
    while (n--) {
        sum = sum.plus(rows[n + 1]);
    }
    console.log(sum.toString(10).substring(0, 10));
} 

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});
