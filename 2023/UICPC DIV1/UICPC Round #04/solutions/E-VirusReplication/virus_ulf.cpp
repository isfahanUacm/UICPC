#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char before[100001], after[100001];
    cin >> before >> after;
    int s = 0, l1 = strlen(before), l2 = strlen(after), e1 = l1, e2 = l2;
    for (; before[s] && before[s] == after[s]; ++s);
    for (; e1>=0 && e2>=0 && before[e1]==after[e2]; --e1, --e2);
    cout << max(max(0,l2-l1),e2-s+1) << endl;
}
