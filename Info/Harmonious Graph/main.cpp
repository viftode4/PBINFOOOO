#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define mp make_pair
long long n, m, nr, sol;
vector<long long>g[200001];
long long p[200001];
vector<long long>v[200001];
vector<pair<long long, long long>>s;
void dfs( long long nod )
{
    p[nod] = nr;
    v[nr].pb( nod );

    for( auto it : g[nod] )
        if( !p[it] )
            dfs( it );

}
int main()
{
    cin >> n >> m;

    for( int i = 1; i <= m; i++ )
        {
            int x, y;
            cin >> x >> y;
            g[x].pb( y );
            g[y].pb( x );
        }

    for( int i = 1; i <= n; i++ )
        if( !p[i] )
            {
                nr++;
                dfs( i );
            }

    for( int i = 1; i <= nr; i++ )
        {
            long long in = 1e9;
            long long fi = -1e9;

            for( auto it : v[i] )
                {
                    in = min( in, it );
                    fi = max( fi, it );
                }

            s.pb( mp( in, fi ) );
        }

    sort( s.begin(), s.end() );
    sol = 0;
    long long st = 0, nd = 0;

    for( auto it : s )
        {
            if( it.st > nd )
                {
                    nd = it.nd;
                    st = it.st;
                    continue;
                }

            if( it.st < nd )
                {
                    sol++;
                    nd = max( nd, it.nd );
                }
        }

    cout << sol;
    return 0;
}
