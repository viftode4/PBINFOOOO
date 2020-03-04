#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
#define INF 1e9
using namespace std;
ifstream fin( "hamilton.in" );
ofstream fout( "hamilton.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
vector<int>g[20];
int n, m;
int dp[1 << 20][20];
int cost[20][20];
int main()
{
    fast();
    fin >> n >> m;

    for( int i = 0; i <= n; i++ )
        for( int j = 0; j <= n; j++ )
            cost[i][j] = INF;

    for( int conf = 0; conf < ( 1 << n ); conf++ )
        for( int i = 0; i < n; i++ )
            dp[conf][i] = INF;

    for( int i = 1; i <= m; i++ )
        {
            int x, y, c;
            fin >> x >> y >> c;
            g[y].pb( x );
            cost[x][y] = c;
        }

    dp[1][0] = 0;

    for( int conf = 1; conf < ( 1 << n ); conf++ )
        for( int i = 1; i < n; i++ )
            if( conf & ( 1 << i ) )
                for( auto it : g[i] )
                    dp[conf][i] = min( dp[conf][i], dp[conf - ( 1 << i )][it] + cost[it][i] );

    int sol = INF;

    for( auto it : g[0] )
        sol = min( sol, dp[( 1 << n ) - 1][it] + cost[it][0] );

    if( sol == INF )
        fout << "Nu exista solutie";
    else
        fout << sol;

    return 0;
}
