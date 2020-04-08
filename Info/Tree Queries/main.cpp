#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "xxx.in" );
ofstream fout( "xxx.in" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
int n, m;
vector<int>g[200005];
int p[200005];
int use[200005];
void dfs( int x )
{
    use[x];

    for( auto it : g[x] )
        if( !use[it] )
            {
                p[it] = x;
                dfs( it );
            }
}
int main()
{
    fast();
    cin >> n >> m;

    for( int i = 1; i < n; i++ )
        {
            int x, y;
            cin >> x >> y;
            g[x].pb( y );
            g[y].pb( x );
        }

    p[1] = 0;
    dfs( 1 );

    for( int i = 1; i <= m; i++ )
        {
            cin >> x;
        }

    return 0;
}
