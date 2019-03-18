#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "tsunami.in" );
ofstream fout ( "tsunami.out" );
int n, m, h, nr;
short int a[1010][1010];
bool viz[1010][1010];
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
struct pct
{
    int i, j;
} q[1000010];
bool ok ( int i, int j )
{
    if ( i < 1 || i > n || j < 1 || j > m )
        return 0;

    if ( a[i][j] >= h || a[i][j] == 0 )
        return 0;

    if ( viz[i][j] )
        return 0;

    return 1;
}
void bfs ( int i, int j )
{
    int u = 1, p = 1;
    q[1].i = i;
    q[1].j = j;

    while( p <= u )
        {
            if ( a[q[p].i][q[p].j] != 0 )
                nr++;

            for ( int d = 0; d < 4; d++ )
                if ( ok ( q[p].i + di[d], q[p].j + dj[d] ) )
                    {
                        u++;
                        q[u].i = q[p].i + di[d];
                        q[u].j = q[p].j + dj[d];
                        viz[q[u].i][q[u].j] = 1;
                    }

            p++;
        }
}
int main()
{
    fin >> n >> m >> h;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            fin >> a[i][j];

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            if (  a[i][j] == 0 )
                bfs ( i, j );

    fout << nr;
    return 0;
}
