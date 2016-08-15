process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();    
});

function readLine() {
    return input_stdin_array[input_currentline++];
}

/////////////// ignore above this line ////////////////////

function main() {
    var n = parseInt(readLine());
    var a = readLine().split(' ').map(Number);
    var max = Math.max(...a);
    var sum = a.reduce(function (a, b) {return a + b;}, 0);
    if (n === 1 || (n === 2 && a[0] === a[1])) {
        console.log(2);
    } else if (sum - max <= max) {
        console.log(1);
    } else {
        console.log(0);
    }
}
