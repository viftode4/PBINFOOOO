#include <bits/stdc++.h>
using namespace std;
ifstream fin( "miting.in" );
ofstream fout( "miting.out" );
//base
int cer, n, m;
string cuv;
map <char, int> cc;
char a[100][100];
struct lit
{
    int x, y;
} c[11], q[10010];
//lee
int dx[] = {0, 1, 0, -1, 0};
int dy[] = {0, 0, 1, 0, -1};
int lee[11][100][100];
int p, v;
int in( int i, int j );
int ok( int x, int i, int j );
void addvecini( int x, int i, int j );
void leee( int x );
void afisare( int x );
//cerinta 1
int xmax, xmin = 10000, ymax, ymin = 10000;
//cerinta 2
//costul pentru a reuni subsirul de pe poz i pana la poz j
struct coco
{
    int x, y, val;
} sum[11][11];
void costet();
int cost( int x, int y );
//generarea tuturor secventelor
int main()
{
    fin >> cer;
    fin >> n >> m;
    fin >> cuv;

    for( int i = 0; cuv[i]; i++ )
        {
            cc[cuv[i]] = i + 1;
        }

    int k = cuv.size();

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            {
                fin >> a[i][j];

                if( a[i][j] == '#' )
                    for( int t = 1; t <= k; t++ )
                        lee[t][i][j] = -1;
                else if( a[i][j] >= 'A' && a[i][j] <= 'Z' )
                    {
                        c[cc[a[i][j]]].x = i;
                        c[cc[a[i][j]]].y = j;
                        xmax = max( i, xmax );
                        xmin = min( i, xmin );
                        ymax = max( ymax, j );
                        ymin = min( j, ymin );
                    }
            }

    if( cer == 1 )
        {
            fout << ( xmax - xmin + 1 )*( ymax - ymin + 1 );
            return 0;
        }

    for( int i = 1; i <= k; i++ )
        leee( i );

    //for( int i = 1; i <= k; i++ )
       // afisare( i );

    fout << cost( 1, k );
    return 0;
}
int cost( int x, int y )
{

    int nr = INT_MAX;

    for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= m; j++ )
                {

                    if( lee[1][i][j] != -1 )
                        {
                            int v = 0;

                            for( int t = x; t <= y; t++ )
                                v += lee[t][i][j];
                            if(v!=0)
                            nr = min( nr, v );
                        }
                }
        }

    return nr;
}
void leee( int x )
{
    p = v = 1;
    q[1].x = c[x].x;
    q[1].y = c[x].y;
    a[c[x].x][c[x].y] = 1;

    while( p <= v )
        {
            addvecini( x, q[p].x, q[p].y );
            p++;
        }
}
void addvecini( int x, int i, int j )
{
    for( int d = 1; d <= 4; d++ )
        {
            if( ok( x, i + dx[d], j + dy[d] ) )
                {
                    v++;
                    q[v].x = i + dx[d];
                    q[v].y = j + dy[d];
                    lee[x][q[v].x][q[v].y] = lee[x][q[p].x][q[p].y] + 1;
                }
        }
}
int ok( int x, int i, int j )
{
    if( in( i, j ) && lee[x][i][j] == 0 )
        return 1;

    return 0;
}
int in( int i, int j )
{
    if( i > n || i < 1 || j < 1 || j > m )
        return 0;

    return 1;
}
void afisare( int x )
{
    fout << x << endl;

    for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= m; j++ )
                fout << lee[x][i][j] << ' ';

            fout << endl;
        }
}
