function processData(input) {
    var rows = input.split('\n');
    var data = rows[1].split(' ');
    var [n, k, q] = rows[0].split(' ').map(function (x) {
        return parseInt(x, 10);
    });
    if (k > n) k = k % n;
    data = data.slice(k * -1).concat(data.slice(0, n - k));
    for (var i = 0; i < q; ++i) {
        console.log(data[rows[i + 2]]);
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
