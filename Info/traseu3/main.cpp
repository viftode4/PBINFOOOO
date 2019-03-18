#include <bits/stdc++.h>
using namespace std;
ifstream fin( "traseu.in" );
ofstream fout( "traseu.out" );
const int INF = INT_MAX;
struct pct
{
    int i, j;
} a[250010];
int v[510][510];
int l[510];
int d, dmax, n, m;
int main()
{
    fin >> n >> m;
    int x;

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            {
                fin >> x;
                a[x].i = i;
                a[x].j = j;
            }

    for( int i = 1; i <= n; i++ )
        l[i] = INF;

    for( int t = 1; t <= n * m; t++ )
        {
            d = 0;
            int i = a[t].i;
            int j = a[t].j;

            for( int x = 1; x <= i; x++ )
                if( l[x] <= j )
                    d = max( d, abs( l[x] - j ) + abs( i - x ) );

            v[i][j] = d;
            l[i] = min( l[i], j );
        }

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            d = max( v[i][j], d );

    if( d == 0 )
        fout << 0;
    else
        fout << d + 1 << '\n';

    return 0;
}
