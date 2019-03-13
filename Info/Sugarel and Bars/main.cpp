#include <bits/stdc++.h>
using namespace std;
int n, m;
int x, y;
int h1, h2;
vector <int> a[100010];
int v[3][100010];
int sol[100010];
void dfs( int x, int i )
{
    v[i][x] = 1;

    for( auto it : a[x] )
        if( !v[i][it] )
            dfs( it, i );

}
int main()
{
    cin >> n >> m;
    cin >> h1 >> h2;

    for( int i = 1; i <= m; i++ )
        {
            cin >> x >> y;
            a[y].push_back( x );
        }

    dfs( h1, 1 );
    dfs( h2, 2 );
    int m = 2;

    for( int i = 1; i <= n; i++ )
        {
            sol[i] = 1 - v[1][i] + 1 - v[2][i];
            m = min( m, sol[i] );
        }


    for( int i = 1; i <= n; i++ )
        {
            if( sol[i] > m )
                cout << m + 1 << ' ';
            else
                cout << sol[i] << ' ';
        }

    return 0;
    return 0;
}
