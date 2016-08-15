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
    var pos = 0, neg = 0, zero = 0;
    var n = parseInt(readLine());
    arr = readLine().split(' ');
    arr = arr.map(Number);
    arr.forEach(function(i){
        if (i < 0) {
            ++neg;
        } else if (i === 0) {
            ++zero;
        } else {
            ++pos;
        }
    });
    console.log(pos/n);
    console.log(neg/n);
    console.log(zero/n);
}
