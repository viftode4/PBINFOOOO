#include <bits/stdc++.h>
using namespace std;
ifstream fin( "time.in" );
ofstream fout( "time.out" );
#define pb push_back
vector<int> g[1010];
int n, m, c, sol;
int v[1010];
int use[1010];
int cat[2010];
void dfs( int x, int cost, int p )
{
    if( cost - c * p * p < 0 )
        return;

    use[x] = 1;

    for( auto it : g[x] )
        {
            if( !use[it] )
                dfs( it, cost + v[it], p + 1 );

            if( it == 1 )
                cat[p + 1] = max( cat[p], cost );
        }

    use[x] = 0;
}
int main()
{
    fin >> n >> m >> c;

    for( int i = 1; i <= n; i++ )
        fin >> v[i];

    for( int i = 1; i <= m; i++ )
        {
            int x, y;
            fin >> x >> y;
            g[x].pb( y );
        }

    dfs( 1, 0, 0 );

    for( int i = 1; i <= m; i++ )
        if( cat[i] )
            {
                int x = 1;

                while( ( cat[i]*x - c * i * x * i * x ) > sol )
                    {
                        sol = max( sol, cat[i] * x - c * i * x * i * x );
                        x++;
                    }
            }

    fout << sol;

    return 0;
}
