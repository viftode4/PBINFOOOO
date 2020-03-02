#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "dfs.in" );
ofstream fout( "dfs.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
int use[100005];
int n, m;
int x, y, nrc;
vector<int>g[100005];
void dfs( int x )
{
    use[x] = 1;

    for( auto it : g[x] )
        if( !use[it] )
            dfs( it );
}
int main()
{
    fast();
    fin >> n >> m;

    for( int i = 1; i <= m; i++ )
        {
            fin >> x >> y;
            g[x].pb( y );
            g[y].pb( x );
        }

    for( int i = 1; i <= n; i++ )
        if( !use[i] )
            {
                nrc++;
                dfs( i );
            }

    fout << nrc;
    return 0;
}
