#include <bits/stdc++.h>
using namespace std;
ifstream fin( "spargere.in" );
ofstream fout( "spargere.out" );
int n;
long long b[110];
long long t[110];
int q, x;
int ok( long long x, long long v )
{
    long long s = 0;

    for( int i = 1; i <= n; i++ )
        s = s + ( b[i] * ( x / t[i]+1 ) );

    if( s >= v )
        return 1;

    return 0;
}
int cauta( int x )
{
    long long l = -1, r = x + 1, mid = 0;

    while( r - l > 1 )
        {
            mid = ( l + r ) / 2;

            if( ok( mid, x ) )
                r = mid;
            else
                l = mid;
        }

    return r;
}
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        fin >> b[i] >> t[i];

    fin >> q;

    for( int i = 1; i <= q; i++ )
        {
            fin >> x;
            fout << cauta( x ) << '\n';;
        }

    return 0;
}
