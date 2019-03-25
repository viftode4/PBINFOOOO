#include <iostream>
using namespace std;
int n, nr;
int main()
{
    cin >> n;
    nr = 2;

    while( n > 0 )
        {
            cout << nr << ' ';
            nr += 2;
            n--;
        }

    return 0;
}
