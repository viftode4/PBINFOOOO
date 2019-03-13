#include <bits/stdc++.h>
using namespace std;
ifstream fin( "mr.in" );
ofstream fout( "mr.out" );
struct pct
{
    int i, j;
} po[110][3], q[10100];
int t, p, v;
int n, m;
int di[] = {0, 1, 0, -1, 0};
int dj[] = {0, 0, 1, 0, -1};
int a[110][110];
void lee( int i, int j );
void addvecini( int i, int j );
void addportal( int i, int j );
int ok( int i, int j );
int interior( int i, int j );
int main()
{
    fin >> n >> m;

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            fin >> a[i][j];

    fin >> t;

    for( int i = 1; i <= t; i++ )
        fin >> po[i][1].i >> po[i][1].j >> po[i][2].i >> po[i][2].j;

    lee( 1, 1 );
    fout << a[n][m] - 1;

    return 0;
}
void addportal( int i, int j )
{
    for( int k = 1; k <= t; k++ )
        {
            if( po[k][1].i == i && po[k][1].j == j && ok( po[k][2].i, po[k][2].j ) )
                {
                    v++;
                    q[v].i = po[k][2].i;
                    q[v].j = po[k][2].j;
                    a[q[v].i][q[v].j] = a[q[p].i][q[p].j] + 1;
                }
        }
}
void lee( int i, int j )
{
    p = v = 1;
    q[1].i = 1;
    q[1].j = 1;
    a[1][1] = 1;

    while( p <= v )
        {
            addportal( q[p].i, q[p].j );
            addvecini( q[p].i, q[p].j );
            p++;
        }
}
void addvecini( int i, int j )
{
    for( int d = 1; d <= 4; d++ )
        if( ok( i + di[d], j + dj[d] ) )
            {
                v++;
                q[v].i = q[p].i + di[d];
                q[v].j = q[p].j + dj[d];
                a[q[v].i][q[v].j] = a[q[p].i][q[p].j] + 1;
            }

}
int ok( int i, int j )
{
    if( a[i][j] == 0 && interior( i, j ) )
        return 1;

    return 0;
}
int interior( int i, int j )
{
    if( i < 1 || i > n || j < 1 || j > m )
        return 0;

    return 1;
}
