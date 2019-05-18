#include <bits/stdc++.h>
using namespace std;
ifstream fin( "darb.in" );
ofstream fout( "darb.out" );
int n, last, d, x, y;
vector<int>g[100003];
int dist[100003];
void dfs( int x )
{
    for( auto it : g[x] )
        if( !dist[it] )
            {
                dist[it] = dist[x] + 1;

                if( d < dist[it] )
                    {
                        d = dist[it];
                        last = it;
                    }

                dfs( it );
            }
}
int main()
{
    fin >> n;

    for( int i = 1; i < n; i++ )
        {
            fin >> x >> y;
            g[x].push_back( y );
            g[y].push_back( x );
        }

    dist[1] = 1;
    last = 1;
    dfs( 1 );

    for( int i = 1; i <= n; i++ )
        dist[i] = 0;

    dist[last] = 1;
    d = 0;
    last = last;
    dfs( last );
    fout << dist[last];
    return 0;
}
