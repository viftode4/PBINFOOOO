#include <bits/stdc++.h>
using namespace std;
ifstream fin( "insule.in" );
ofstream fout( "insule.out" );
const int NMAX = 10000000;
int n, m, v;
int nr[5];
int a[110][110];
int b[110][110];
char x;
int di[] = {0, -1, 0, 1, 0};
int dj[] = {0, 0, 1, 0, -1};
struct que
{
    int i, j, l;
} q[100000];
void fil( int x, int y )
{
    int v = b[x][y];
    b[x][y] = 0;

    for( int i = 1; i <= 4; i++ )
        if( b[x + di[i]][y + dj[i]] == v )
            fil( x + di[i], y + dj[i] );


}
int main()
{
    cin >> n >> m;

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            {
                cin >> x;
                a[i][j] = x - '0';
                b[i][j] = x - '0';
            }

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            if( b[i][j] != 0 )
                {
                    int v = b[i][j];
                    fil( i, j );
                    nr[v]++;
                    b[i][j] = 0;
                }

    for( int i = 1; i <= 3; i++ )
        cout << nr[i] << '\n';

    v = 0;

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            if( a[i][j] == 1 )
                {
                    b[i][j] = -1;
                    q[++v].i = i;
                    q[v].j = j;
                }
            else if( a[i][j] == 3 )
                b[i][j] = -1;
            else if( a[i][j] == 2 )
                b[i][j] = -3;

    for( int i = 0; i <= n + 1; i++ )
        b[i][0] = b[i][m + 1] = -1;

    for( int i = 0; i <= m + 1; i++ )
        b[0][i] = b[n + 1][i] = -1;

    int p = 0;
    int ok = 1;

    while( p <= v && ok )
        {
            p++;

            for( int i = 1; i <= 4; i++ )
                if( b[q[p].i + di[i]][q[p].j + dj[i]] == 0 && a[q[p].i + di[i]][q[p].j + dj[i]] != 1 )
                    {
                        v++;
                        q[v].i = q[p].i + di[i];
                        q[v].j = q[p].j + dj[i];
                        b[q[v].i][q[v].j] =  b[q[p].i][q[p].j] + 1 ;
                    }
                else if( b[q[p].i + di[i]][q[p].j + dj[i]] == -3 &&  b[q[p].i][q[p].j] != -1 )
                    {
                        cout << b[q[p].i][q[p].j] << '\n';
                        ok = 0;
                    }
        }


    for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= m; j++ )
                cout << b[i][j] << ' ';

            cout << endl;
        }

    /*
        int lgmin = NMAX;

        for( int i = 1; i <= n; i++ )
            for( int j = 1; j <= m; j++ )
                if( a[i][j] == 2 && b[i][j] != 0 )
                    lgmin = min( lgmin, b[i][j] );

        cout << lgmin;*/
    return 0;
}
