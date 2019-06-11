#include <bits/stdc++.h>
using namespace std;
ifstream fin( "asmax.in" );
ofstream fout( "asmax.out" );
int n, x, y;
int sol = -1 * INT_MAX;
vector<int>g[16005];
int cost[16005];
int use[16005];
int dp[16005];
void dfs( int x )
{
    use[x] = 1;

    for( auto it : g[x] )
        if( !use[it] )
            {
                dfs( it );

                if( dp[it] > 0 )
                    dp[x] += dp[it];
            }
}
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        {
            fin >> cost[i];
            dp[i] = cost[i];
        }

    for( int i = 1; i < n; i++ )
        {
            fin >> x >> y;
            g[x].push_back( y );
            g[y].push_back( x );
        }

    dfs( 1 );

    for( int i = 1; i <= n; i++ )
        sol = max( sol, dp[i] );

    fout << sol;
    return 0;
}
