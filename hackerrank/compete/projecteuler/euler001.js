var BigNumber = require('bignumber.js');

/*
Triangular numbers:
1 3 6 10 15 21

Div:  3
Nums: 3 6 9  12 15 18
Sums: 3 9 18 30 45 63

Div:  5
Nums: 5 10 15 20 25 30
Sums: 5 15 30 50 75 105

Div:  15
Nums: 15 30 45 60
Sums: 15 45 90 150

Sums/Div = triangular numbers.
The nth triangular number: n*(n+1)/2
Nth trinagular number * div = sum for that div
*/

function processData(input) {
    var rows = input.split('\n');
    var n = rows[0];
    var num, three, five, fifteen;
    for (var i = 1; i <= n; ++i) {
        --rows[i];
        num = new BigNumber(rows[i]);
        three = num.dividedBy(3).floor();
        five = num.dividedBy(5).floor();
        fifteen = num.dividedBy(15).floor();
        console.log(
            three.times(
                three.plus(1).dividedBy(2)
            ).times(3).plus(
            five.times(
                five.plus(1).dividedBy(2)
            ).times(5)).minus(
            fifteen.times(
                fifteen.plus(1).dividedBy(2)
            ).times(15)).toString(10)
        );
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
