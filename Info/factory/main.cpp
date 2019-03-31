#include <bits/stdc++.h>
using namespace std;
ifstream fin( "factory.in" );
ofstream fout( "factory.out" );
int viz[110];
vector<int>g[110];
int n, x, y;
void gol()
{
    for( int i = 1; i <= 100; i++ )
        viz[i] = 0;
}
int ok()
{
    for( int i = 1; i <= n; i++ )
        if( viz[i] == 0 )
            return 0;

    return 1;
}
void dfs( int i )
{
    viz[i] = 1;

    for( auto it : g[i] )
        if( !viz[it] )
            dfs( it );
}
int main()
{
    fin >> n;

    for( int i = 1; i < n; i++ )
        {
            fin >> x >> y;
            g[y].push_back( x );
        }

    for( int i = 1; i <= n; i++ )
        {
            gol();
            dfs( i );

            if( ok() )
                {
                    fout << i;
                    return 0;
                }
        }

    fout << -1;
    return 0;
}
