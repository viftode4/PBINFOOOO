#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ifstream fin( "in.in" );
const ull MOD = 1e9 + 7;
ull n, k;
vector<ull>g[200010];
ull viz[200010];
ull x, y, c;
ull sum, cate;
ull dif;
ull fpw( ull base, ull exp )
{
    ull r = 1;

    while( exp )
        {
            if( exp % 2 == 1 )
                r = ( r * base ) % MOD;

            base = ( base * base ) % MOD;
            exp = exp / 2;
        }

    return r;
}
ull f( ull n )
{
    return fpw( n, k );
}
ull dfs( ull i )
{
    viz[i] = 1;
    cate++;

    for( auto it : g[i] )
        if( !viz[it] )
            dfs( it );

}
int main()
{
    cin >> n >> k;
    sum = f( n );
    // cout << sum << ' ';

    for( ull i = 1; i < n; i++ )
        {
            cin >> x >> y >> c;

            if( c == 0 )
                {
                    g[x].push_back( y );
                    g[y].push_back( x );
                }
        }

    for( ull i = 1; i <= n; i++ )
        if( !viz[i] )
            {
                cate = 0;
                dfs( i );
                sum = ( sum - f( cate ) + MOD ) % MOD;

            }

    cout << sum;
    return 0;
}
