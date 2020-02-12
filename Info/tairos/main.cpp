#include <bits/stdc++.h>
#define pb push_back
#define MOD 1000000007
#define ll long long
using namespace std;
ifstream fin ( "tairos.in" );
ofstream fout ( "tairos.out" );
ll n, d, x, y;
ll sol;
vector<ll>g[110], f;
ll use[110];
ll p[110];
ll dp[10005][105];
void dfs ( ll x, ll ant )
{
    int ok = 1;
    p[x] = ant;

    for ( auto it : g[x] )
        if ( !use[it] )
            {
                use[it] = use[x] + 1LL;
                dfs ( it, x );
                ok = 0;
            }

    if ( ok )
        f.pb ( x );
}
int main()
{
    fin >> n >> d;

    for ( int i = 1; i < n; i++ )
        {
            fin >> x >> y;
            g[x].pb ( y );
            g[y].pb ( x );
        }

    use[1] = 1;
    dfs ( 1, 0 );
    dp[1][1] = 1;
    //dp[0][0] = 1;
   // dp[0][1] = 1;

    for ( int k = 1; k <= d; k++ )
        for ( int i = 1; i <= n; i++ )
            {
                if ( p[i] != 1 )
                    {
                        dp[k][i] = ( dp[k][i] + dp[k - 1][p[i]] ) % MOD;
                    }
                else
                    {
                        dp[k][i] = ( dp[k][i] + dp[k][1] ) % MOD;

                        for( auto it : f )
                            dp[k][i] = ( dp[k][i] + dp[k - 1][it] ) % MOD;
                    }
            }

    for( int i = 1; i <= n; i++ )
        sol = ( sol + dp[d][i] ) % MOD;

    fout << ( sol ) % MOD;
    return 0;
}
