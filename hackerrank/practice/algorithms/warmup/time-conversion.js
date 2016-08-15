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
    var time = readLine();
    var daypart = time.slice(-2);
    time = time.slice(0,-2);
    time = time.split(':');
    if (daypart === 'PM') {
        if (time[0] !== '12') {
            time[0] = parseInt(time[0], 10) + 12;
        }
    } else if (time[0] === '12') {
        time[0] = '00';
    }
    console.log(time.join(':'));
}
