function processData(input) {
    var rows = input.split('\n');
    var currentRow = 0;
    var t = rows[currentRow++];
    while (currentRow < t * 3 + 1) {
        var m = parseInt(rows[currentRow++], 10);
        var n = rows[currentRow++];
        var list = rows[currentRow++].split(' ').map(Number);
        
        searchInList: for (var i = 0; i < n; ++i) {
            for (var j = i + 1; j < n; ++j) {
                if (list[i] + list[j] === m) {
                    console.log(i + 1, j + 1);
                    break searchInList;
                }
            }
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
