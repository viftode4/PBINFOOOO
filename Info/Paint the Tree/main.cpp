#include <bits/stdc++.h>
using namespace std;
int n, x, y;
long long sum = 0;
vector<int>g[100005];
int c[4][100005];
int sol[100005];
void dfs( int x )
{
    int culmin = 0;

    for( int i = 1; i <= 3; i++ )
        {
            int ok = 0;

            for( auto it : g[x] )
                {
                    if( sol[it] == i )
                        {
                            ok = 1;
                            break;
                        }
                }

            if( !ok && c[culmin][x] > c[i][x] )
                culmin = i;
        }

    sol[x] = culmin;
    sum += c[culmin][x];

    for( auto it : g[x] )
        if( !sol[it] )
            dfs( it );
}
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> c[1][i];
            c[0][i] = INT_MAX;
        }

    for( int i = 1; i <= n; i++ )
        cin >> c[2][i];

    for( int i = 1; i <= n; i++ )
        cin >> c[3][i];

    for( int i = 1; i < n; i++ )
        {
            cin >> x >> y;
            g[x].push_back( y );
            g[y].push_back( x );
        }

    for( int i = 1; i <= n; i++ )
        if( g[i].size() > 2 )
            {
                cout << -1;
                return 0;
            }

    dfs( 1 );
    cout << sum << '\n';

    for( int i = 1; i <= n; i++ )
        cout << sol[i] << ' ';

    return 0;
}
