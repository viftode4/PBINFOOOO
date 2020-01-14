#include <bits/stdc++.h>
using namespace std;
ifstream fin( "iepuri2.in" );
ofstream fout( "iepuri2.out" );
#define MOD 30011
vector<int>g[110];
int n, k;
int iepurila;
int dp[110][110];
int grad[110];
void dfs( int x )
{
    for( int i = 1; i <= k; i++ )
        dp[x][i] = 1;

    for( auto it : g[x] )
        {
            dfs( it );

            for( int i = 1; i <= k; i++ )
                dp[x][i] = ( dp[x][i] * dp[it][i + 1] ) % MOD;
        }

    for( int i = k; i >= 1; i-- )
        dp[x][i] = ( dp[x][i] + dp[x][i + 1] ) % MOD;
}
int main()
{
    fin >> n >> k;

    for( int i = 1; i < n; i++ )
        {
            int x, y;
            fin >> x >> y;
            g[x].push_back( y );
            grad[y]++;
        }

    for( int i = 1; i <= n; i++ )
        if( grad[i] == 0 )
            {
                iepurila = i;
                break;
            }

    dfs( iepurila );
    fout << dp[iepurila][1];

    return 0;
}
