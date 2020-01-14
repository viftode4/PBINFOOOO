#include <bits/stdc++.h>
using namespace std;
ifstream fin( "graf.in" );
ofstream fout( "graf.out" );
int n, m, x, y, a, b, d;
int dx[7600], dy[7600];
int fr[7600];
vector<int> g[7600];
void afisare( int x, int dx[7600] )
{
    fout << x << '\n';

    for( int i = 1; i <= n; i++ )
        fout << "NODUL: " << i << " DIST: " << dx[i] << '\n';
}
void bfs( int x, int d[7600] )
{
    queue<int>q;
    q.push( x );
    d[x] = 1;

    while( !q.empty() )
        {
            int t = q.front();
            q.pop();

            for( auto it : g[t] )
                if( !d[it] )
                    {
                        d[it] = 1 + d[t];
                        q.push( it );
                    }

        }
}
int main()
{
    fin >> n >> m >> x >> y;

    for( int i = 1; i <= m; i++ )
        {
            fin >> a >> b;
            g[a].push_back( b );
            g[b].push_back( a );
        }

    bfs( x, dx );
    bfs( y, dy );
    d = dx[y];
    //cout<<d;
    //afisare( x, dx );
    //afisare( y, dy );
    int sol[7600], p = 0;

    for( int i = 1; i <= n; i++ )
        if( dx[i] + dy[i] - 1 == dx[y] )
            fr[dx[i]]++;


    for( int i = 1; i <= n; i++ )
        if( dx[i] + dy[i] - 1 == dx[y] && fr[dx[i]] == 1 )
            sol[++p] = i;

    fout << p << '\n';

    for( int i = 1; i <= p; i++ )
        fout << sol[i] << ' ';

    return 0;
}
