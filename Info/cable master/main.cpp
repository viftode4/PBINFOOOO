#include <bits/stdc++.h>
using namespace std;
int n, k;
double a[100001], r;
int ok( double m )
{
    int nr = 0;

    for( int i = 1; i <= n; i++ )
        nr = nr + ( int )( a[i] / m );

    return nr >= k;
}
int main()
{
    cin >> n >> k;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a[i];
            r = max( r, a[i] );
        }

    double l = 0;

    while( r - l > 0.01 )
        {
            double m = ( r + l ) / 2.00;

            if( ok( m ) )
                l = m;
            else
                r = m;
        }

        if(ok(l))
    cout << setprecision( 2 ) << fixed <<l;
    else cout << setprecision( 2 ) << fixed <<r;
    return 0;
}
