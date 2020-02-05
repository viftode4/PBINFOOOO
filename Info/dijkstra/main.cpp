#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define nd second
#define st first
#define pb push_back
#define INF 2000005
ifstream fin( "dijkstra.in" );
ofstream fout( "dijkstra.out" );
priority_queue < pair<int, int> >pq;
vector<pair<int, int>>g[50005];
int dist[50005];
int n, m;
int main()
{
    fin >> n >> m;

    for( int i = 1; i <= m; i++ )
        {
            int x, y, z;
            fin >> x >> y >> z;
            g[x].pb( mp( y, z ) );
        }

    for( int i = 1; i <= n; i++ )
        dist[i] = INF;

    dist[1] = 0;
    pq.push( mp( 0, 1 ) );

    while( !pq.empty() )
        {
            auto t = pq.top();
            pq.pop();

            if( -t.st > dist[t.nd] )
                continue;

            for( auto it : g[t.nd] )
                if( dist[t.nd] + it.nd < dist[it.st] )
                    {
                        dist[it.st] = dist[t.nd] + it.nd;
                        pq.push( mp( -dist[it.st], it.st ) );
                    }
        }

    for( int i = 2; i <= n; i++ )
        fout << ( dist[i] < INF ? dist[i] : 0 ) << ' ';

    return 0;
}
