#include <iostream>
using namespace std;
int n, x, r1, r2, r3;
int main()
{
    cin >> n;
    for ( int i = 1; i <= n; i++ )
    {
        cin >> x;
        if ( x % 3 == 1 )
        {
            r2 += 1;
            r3 += 2;
        }
        else if ( x % 3 == 2 )
        {
            r1 += 2;
            r3 += 1;
        }
        else
        {
            r1 += 1;
            r2 += 2;
        }
    }
    cout << min ( min ( r1, r2 ), r3 );
    return 0;
}
