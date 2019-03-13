#include <bits/stdc++.h>
using namespace std;
ifstream fin( "zona2.in" );
ofstream fout( "zona2.out" );
int x, y, n, l, d, nr;
int a[56][56];
int dx[5] = {0, -1, 0, 1, 0};
int dy[5] = {0, 0, 1, 0, -1};
int in( int x, int y )
{
    if( x >= 1 && x <= n && y >= 1 && y <= n )
        return 1;

    return 0;
}
void fil( int i, int j )
{
    for( int d = 1; d <= 4; d++ )
        if( a[i + dx[d]][j + dy[d]] == 0 && in( i + dx[d], j + dy[d] ) )
            {
                a[i + dx[d]][j + dy[d]] = 2;
                fil( i + dx[d], j + dy[d] );
            }
}
int main()
{
    fin >> x >> y >> n >> l;
    n++;
    x++;
    y++;
    a[x][y] = 1;
    int p = 0;

    for( int i = 1; i <= l; i++ )
        {
            fin >> d;
            x += dx[d];
            y += dy[d];

            if( a[x][y] == 1 )
                break;
            else
                {
                    a[x][y] = 1;
                    p++;
                }
        }

    int ok = 0;

    for( int i = 1; i <= n && !ok; i++ )
        {
            for( int j = 1; j <= n; j++ )
                if( a[i][j] == 1 )
                    continue;
                else
                    {
                        a[i][j] = 2;
                        fil( i, j );
                        ok = 1;
                        break;
                    }

            if( ok == 1 )
                break;
        }

    nr = 0;

    for( int i = 1; i <= n - 1; i++ )
        for( int j = 1; j <= n - 1; j++ )
            if( a[i][j] != 2 && a[i + 1][j + 1] != 2 && a[i + 1][j] != 2 && a[i][j + 1] != 2 )
                nr++;

    fout << p - 1 << endl;
    fout << nr << ' ';
    return 0;
}
