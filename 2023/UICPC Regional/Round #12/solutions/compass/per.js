// I have no idea what I'm doing.

var n1 = parseInt(readline());
var n2 = parseInt(readline());
n2 -= n1;
if (n2 > 180) {
    n2 -= 360;
}
if (n2 <= -180) {
    n2 += 360;
}
print(n2);
