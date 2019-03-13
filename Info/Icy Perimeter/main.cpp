#include <bits/stdc++.h>
using namespace std;
ifstream fin( "perimeter.in" );
ofstream fout( "perimeter.out" );
const int N = 1e4 + 10;
int a[N][N], n;
char x;
int v, p, per, amax, pmin = INT_MAX;
int di[] = {0, 0, 1, 0, -1};
int dj[] = {0, 1, 0, -1, 0};
struct q
{
    int i, j;
} q[100010];
void fil( int x, int y )
{

    q[1].i = x;
    q[1].j = y;
    a[x][y] = 2;
    v = 1;
    p = 0;
    per = 0;

    while( p < v )
        {
            p++;

            for( int d = 1; d <= 4; d++ )
                if( a[q[p].i + di[d]][q[p].j + dj[d]] == 1 )
                    {
                        a[q[p].i + di[d]][q[p].j + dj[d]] = 2;
                        v++;
                        q[v].i = q[p].i + di[d];
                        q[v].j = q[p].j + dj[d];
                    }
                else if( a[q[p].i + di[d]][q[p].j + dj[d]] == 0 )
                    per++;
        }
}
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= n; j++ )
            {
                fin >> x;

                if( x == '#' )
                    a[i][j] = 1;
                else
                    a[i][j] = 0;
            }

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= n; j++ )
            if( a[i][j] == 1 )
                {
                    v = 1;
                    p = 0;
                    per = 0;
                    fil( i, j );

                    if( v > amax )
                        {
                            amax = v;
                            pmin = per;
                        }
                    else if( v == amax && pmin > per )
                        pmin = per;

                }

    fout << amax << ' ' << pmin;
    return 0;
}
