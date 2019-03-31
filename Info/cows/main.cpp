#include <bits/stdc++.h>
using namespace std;
ifstream fin( "buckets.in" );
ofstream fout( "buckets.out" );
const int n = 10;
char x;
int v;
int viz[11][11];
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
struct pct
{
    int i, j;
} a[4];
int m[5][11][11];
int ok( int i, int j )
{
    if( viz[i][j] )
        return 0;

    if( i < 1 || i > n || j < 1 || j > n )
        return 0;

    return 1;
}
void bfs( pct x, int k )
{
    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= n; j++ )
            if( viz[i][j] != -1 )
                viz[i][j] = 0;

    queue<pct>q;
    q.push( x );
    m[k][x.i][x.j] = 1;

    while( !q.empty() )
        {
            pct t = q.front();
            q.pop();
            int i, j;
            i = t.i;
            j = t.j;

            for( int d = 0; d < 4; d++ )
                if( ok( i + di[d], j + dj[d] ) )
                    {
                        pct b;
                        b.i = i + di[d];
                        b.j = j + dj[d];
                        m[k][b.i][b.j] = m[k][i][j] + 1;
                        viz[b.i][b.j] = 1;
                        q.push( b );
                    }
        }
}
int main()
{
    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= n; j++ )
            {
                fin >> x;

                if( x != '.' )
                    {
                        a[++v].i = i;
                        a[v].j = j;
                        viz[i][j] = -1;
                    }
            }

    bfs( a[1], 1 );
    bfs( a[2], 2 );
    bfs( a[3], 3 );
    int dist = 99999999;

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= n; j++ )
            {
                if( viz[i][j] != -1 )
                    dist = min( dist, m[1][i][j] + m[2][i][j] + m[3][i][j] - 5 );
            }

    fout << dist;

    return 0;
}
