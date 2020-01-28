#include <bits/stdc++.h>
using namespace std;
#define pb push_back
long long n, sol;
long long s[200005];
long long dp[200005];
vector<int>g[200005];
void siz( int x, int p = -1 );
void calcdp( int x, int p = -1 );
void dfs( int x, int p = -1 );
int main()
{
    cin >> n;

    for( int i = 2; i <= n; i++ )
        {
            int x, y;
            cin >> x >> y;
            g[x].pb( y );
            g[y].pb( x );
        }

    siz( 1 );
    calcdp( 1 );
    dfs( 1 );
    cout << sol;
    return 0;
}
void siz( int x, int p )
{
    s[x] = 1;

    for( auto it : g[x] )
        {
            if( p == it )
                continue;

            siz( it, x );
            s[x] += s[it];
        }
}
void calcdp( int x, int p )
{
    dp[x] = s[x];

    for( auto it : g[x] )
        {
            if( it == p )
                continue;

            calcdp( it, x );
            dp[x] += dp[it];
        }
}
void dfs( int x, int p )
{
    sol = max( sol, dp[x] );

    for( auto it : g[x] )
        {
            if( it == p )
                continue;

            dp[x] -= s[it];
            dp[x] -= dp[it];
            s[x] -= s[it];
            s[it] += s[x];
            dp[it] += dp[x];
            dp[it] += s[x];

            dfs( it, x );

            s[it] -= s[x];
            dp[it] -= dp[x];
            dp[it] -= s[x];
            dp[x] += s[it];
            dp[x] += dp[it];
            s[x] += s[it];

        }
}
