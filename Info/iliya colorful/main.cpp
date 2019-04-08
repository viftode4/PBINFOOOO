#include <bits/stdc++.h>
using namespace std;
int n, a[300005];
int st, dr, dmax;
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a[i];

            if( i == 1 )
                st = a[i];
            else if( i == n )
                dr = a[i];
        }

    if( st != dr )
        {
            cout << n - 1;
            return 0;
        }

    dmax = 0;

    for( int i = 2; i < n; i++ )
        {
            if( a[i] != st )
                dmax = max( dmax, abs( 1 - i ) );

            if( a[i] != dr )
                dmax = max( dmax, abs( n - i ) );
        }

    cout << dmax;
    return 0;
}
