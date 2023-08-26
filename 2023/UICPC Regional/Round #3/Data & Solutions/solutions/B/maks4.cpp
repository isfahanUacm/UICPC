/* Same solution as maks.c, but using different I/O functions.

   Note that no manual flushing is required because std::cin is tied to
   std::cout by default!

   @EXPECTED_RESULTS@: CORRECT
*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    int r1, c1, r2, c2, cases = 0;
    string line;
    getline(cin, line);
    istringstream(line) >> cases;
    while (cases-- > 0)
    {
        cout << 5 << ' ' << 1 << ' ' << 5 << ' ' << 6 << '\n';
        for (;;)
        {
            string line, id;
            getline(cin, line);
            istringstream iss(line);
            iss >> id;
            if (id == "GAME") break;
            iss >> r1 >> c1 >> r2 >> c2;
            if (r1 > 4) r1 = 4;
            if (r2 > 4) r2 = 4;
            cout << 5-r2 << ' ' << 7-c2 << ' ' << 5-r1 << ' ' << 7-c1 << '\n';
        }
    }
    return 0;
}
