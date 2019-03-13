#include <bits/stdc++.h>
using namespace std;
ifstream fin( "uscat.in" );
ofstream fout( "uscat.out" );
long long a[100010], n, x, t;
int ok( int m )
{
    long long t = 0;

    if( x > 1 )
        for( int i = 1; i <= n; i++ )
            if( a[i] > m )
                t += ( x + a[i] - m - 2 ) / ( x - 1 );

    if( t > m )
        return 0;

    return 1;
}
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        {
            fin >> a[i];
            t = max( t, a[i] );
        }

    fin >> x;
    int l = 1, r = t;

    while( r - l > 1 )
        {
            int m = ( l + r ) / 2;

            if( ok( m ) )
                r = m;
            else
                l = m;
        }

    fout << r;
    return 0;
}
