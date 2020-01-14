#include <bits/stdc++.h>
using namespace std;
long long n, imin, cmin, ok, nr2;
int tip[2020];
int use[2020];
long long c[2020];
long long k[2020], nrc;
long long sum = 0;
vector<int>g[2020];
bool sol[2020][2020];
bool mm[2020][2020];
struct coord
{
    long long x, y;
} a[2020];
long long dist( coord a, coord b )
{
    return( abs( a.x - b.x ) + abs( a.y - b.y ) );
}
dfs( int x )
{
    if( tip[x] == 2 )
        ok = 1;

    if( cmin > c[x] )
        {
            cmin = c[x];
            imin = x;
        }

    for( auto it : g[x] )
        if( !use[it] )
            {
                use[it] = 1;
                dfs( it );
            }
}
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        cin >> a[i].x >> a[i].y;

    for( int i = 1; i <= n; i++ )
        cin >> c[i];

    for( int i = 1; i <= n; i++ )
        cin >> k[i];

    for( int i = 1; i <= n; i++ )
        {

            long long smin = INT_MAX, imin = 0;

            for( int j = 1; j <= n; j++ )
                {
                    if( j == i )
                        continue;

                        {
                            smin = dist( a[i], a[j] ) * ( k[i] + k[j] );
                            imin = j;
                        }
                }

            if( smin >= c[i] )
                {
                    sum += c[i];
                    tip[i] = 2;
                    nr2++;
                    else
                        {
                            if( !mm[i][imin] )
                                {
                                    g[i].push_back( imin );
                                    g[imin].push_back( i );
                                    mm[i][imin] = mm[imin][i] = 1;
                                    sum += smin;
                                    tip[i] = 1;
                                }

                            nrc++;
                        }

                    //cout << sum << '\n';
                }

            for( int i = 1; i <= n; i++ )
                if( !use[i] )
                    {
                        ok = 0;
                        use[i] = 1;
                        cmin = c[i];
                        imin = i;
                        dfs( i );

                        if( !ok )
                            {
                                nr2++;
                                tip[imin] = 2;
                                sum += c[imin];
                            }
                    }

            cout << sum << '\n';
            cout << nr2 << '\n';

            for( int i = 1; i <= n; i++ )
                if( tip[i] == 2 )
                    cout << i << ' ';

            cout << '\n';
            cout << nrc << '\n';

            for( int i = 1; i <= n; i++ )
                {
                    for( auto it : g[i] )
                        if( !sol[i][it] )
                            {
                                sol[i][it] = sol[it][i] = 1;
                                cout << i << ' ' << it << '\n';
                            }
                }

            return 0;
        }
