function processData(input) {
    var rows = input.split('\n');
    var nums = rows[2].split(' ');
    for (var i = 0; i < rows[1]; ++i) {
        if (nums[i] == rows[0]) {
            console.log(i);
            break;
        }
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
