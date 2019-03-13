#include <fstream>
using namespace std;
ifstream fin( "schior.in" );
ofstream fout( "schior.out" );
#define maxx 10000
struct q {
    int i, j;
} q[1000003];
int di[] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
int dj[] = {0, 1, 0, -1, 0, 1, -1, -1, 1};
int n, m, x, y, a[104][104], lmin, p, u;
int main() {
    fin >> n >> m;
    fin >> x >> y;

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            fin >> a[i][j];
    for(int i=0; i<=n+1; i++)
        a[0][i]=a[n+1][i]=maxx;
    for(int i=0; i<=m+1; i++)
        a[i][0]=a[i][m+1]=maxx;
    q[1].i = x;
    q[1].j = y;
    p = u = 1;
    lmin = a[x][y];
    while( p <= u ) {
        for( int d = 1; d <= 8; d++ )
            if( a[q[p].i + di[d]][q[p].j + dj[d]] <= a[q[p].i][q[p].j] ) {
                u++;
                q[u].i = q[p].i + di[d];
                q[u].j = q[p].j + dj[d];
            }
        lmin = min( lmin, a[q[p].i][q[p].j] );
        a[q[p].i][q[p].j] = maxx;
        p++;
    }
    fout<<lmin;
    return 0;
}
