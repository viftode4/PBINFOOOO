#include <bits/stdc++.h>
using namespace std;
int n,  a[105], r1, r2;
int main()
{
    cin >> n;

    for( int i = 1; i <= n / 2; i++ )
        cin >> a[i];

    sort( a + 1, a + n / 2 + 1 );
    r1 = r2 = 0;

    for( int i = 1; i <= n / 2; i++ )
        {
            r1 = r1 + abs( a[i] - ( 2 * i - 1 ) );//dist pana la cea mai apropiata dintre casutele negre
            r2 = r2 + abs( a[i] - ( 2 * i  ) );//dist pana la cea mai apropiata dintre casutele albe
        }

    cout << min( r1, r2 );
    return 0;
}
