#include <iostream>
#include <map>
#include <math.h>

using  namespace std;


struct loc{
    int x,y;
};

int main() {
    map<unsigned long long int,loc> distances;

    unsigned long long r ;
    cin >> r;

    long long int i=1 , j = r;
    unsigned long long dis = r*r;

    while (j >= (sqrt(2)/2) * r) {
        unsigned long long dis_2 =(i*i)+(j*j);
        while (dis_2 <= (r * r) )
        {
            i++;
            dis_2 = (i*i)+(j*j);
        }

        loc l;
        l.x = i;
        l.y = j;
        distances[dis_2] = l;
        j--;
    }

    cout << distances.begin()->second.x << ' ' << distances.begin()->second.y;

    return 0;
}
