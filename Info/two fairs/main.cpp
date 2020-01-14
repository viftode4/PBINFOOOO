#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define pb push_back
int t, n, m, a, b;
vector<int>g[200005];
int usea[200005];
int useb[200005];
int nra, nrb;
void dfsa( int x )
{
    usea[x] = 1;
    nra++;

    for( auto it : g[x] )
        if( !usea[it] && it != b )
            dfsa( it );
}
void dfsb( int x )
{
    useb[x] = 1;
    nrb++;

    for( auto it : g[x] )
        if( !useb[it] && it != a )
            dfsb( it );
}
int main()
{
    cin >> t;

    while( t-- )
        {
            cin >> n >> m >> a >> b;
            int x, y;
            nra = nrb = 0;

            for( int i = 1; i <= n; i++ )
                {
                    usea[i] = useb[i] = 0;
                    g[i].clear();
                }

            for( int i = 1; i <= m; i++ )
                {
                    cin >> x >> y;
                    g[x].pb( y );
                    g[y].pb( x );
                }

            dfsa( a );
            dfsb( b );
            x = n - nra - 1;
            y = n - nrb - 1;
            cout << ( long long )x*y << '\n';
        }

    return 0;
}
