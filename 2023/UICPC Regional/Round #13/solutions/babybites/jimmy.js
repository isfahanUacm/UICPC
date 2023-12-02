// I have some idea what I'm doing.

var n = parseInt(readline());
var words = readline().split(' ');
var sense = true;
for(i=0;i<n;i++) {
    if (words[i] != 'mumble' && words[i] != i + 1) sense = false;
}
print(sense ? "makes sense" : "something is fishy");
