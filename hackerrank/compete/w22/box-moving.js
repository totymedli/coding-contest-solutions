// NON FINISHED SOLUTION

var BigNumber = require('bignumber.js');

function processData(input) {
    var rows = input.split('\n');
    var n = rows[0];
    var X = rows[1].split(' ').map(Number);
    var Y = rows[2].split(' ').map(Number);
    var sumNeg = new BigNumber(0);
    var sumPos = new BigNumber(0);
    var a = null, b = null, dif = null;
    X.sort();
    Y.sort();
    for (var i = 0; i < n; ++i) {
        a = new BigNumber(X[i]);
        b = new BigNumber(Y[i]);
        dif = a.minus(b);
        if (dif.lessThan(0)) {
            sumNeg = sumNeg.plus(dif);
        } else if (!dif.equals(0)) {
            sumPos = sumPos.plus(dif);
        }
    }
    if (sumNeg.plus(sumPos).equals(0)) {
        console.log(sumPos.toString(10));
    } else {
        console.log(-1);
    }
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
