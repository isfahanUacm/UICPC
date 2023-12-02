var n = parseInt(readline());
var temp = readline().split(' ');
var best = 99, bestDay;
for(var i=0;i<n-2;i++) {
    var hottest = Math.max(temp[i], temp[i+2]);
    if (hottest < best) {
        best = hottest;
        bestDay = i+1;
    }
}
print(bestDay + " " + best);
