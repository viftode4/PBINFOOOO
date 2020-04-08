#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
#define MOD 30011
using namespace std;
ifstream fin( "iepuri1.in" );
ofstream fout( "iepuri1.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
ll n, k, rad;
ll dp[110][110], tata[110];
ll sp[110];
vector<int>g[110];
void dfs( int x )
{
    for( auto it : g[x] )
        dfs( it );

    for( auto it : g[x] )
        {
            ll temp = 1;
            sp[0] = 0;

            for( int i = 1; i <= k; i++ )
                sp[i] = ( sp[i - 1] + dp[it][i] ) % MOD;

            for( int i = 1; i <= k; i++ )
                dp[x][i] = ( dp[x][i] * ( ( sp[k] - sp[i] ) % MOD ) ) % MOD;
        }
}
int main()
{
    fast();
    fin >> n >> k;

    for( int i = 1; i < n; i++ )
        {
            int x, y;
            fin >> x >> y;
            g[x].pb( y );
            tata[y] = x;
        }

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= k; j++ )
            dp[i][j] = 1;

    for( int i = 1; i <= n; i++ )
        if( !tata[i] )
            {
                rad = i;
                break;
            }

    dfs( rad );
    ll sol = 0;

    for( int i = 1; i <= k; i++ )
        sol = ( sol + dp[rad][i] ) % MOD;

    while( sol < 0 )
        sol = ( sol + MOD ) % MOD;

    fout << sol;
    return 0;
}
