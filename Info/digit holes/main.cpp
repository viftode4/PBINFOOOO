#include <iostream>
using namespace std;
int a, b, c, nr, nrmax;
int main()
{
    cin >> a >> b;

    for ( int i = a; i <= b; i++ )
    {
        ci = i;
        nr = 0;
        while ( ci != 0 )
        {
            if ( ci % 10 == 9 || ci % 10 == 6 || ci % 10 == 0 )
                nr++;
            else if ( ci % 10 == 8 )
                nr += 2;
            ci /= 10;
        }
        if ( nr > nrmax )
        {
            nrmax = nr;
            c = i;
        }
    }
    cout << c;
}
