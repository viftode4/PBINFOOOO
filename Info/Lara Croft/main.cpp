#include <bits/stdc++.h>
using namespace std;
int a[110][110], x, y, m, n, c, d;
int main()
{
    cin >> n >> m;
    int ok = 1;
    int nr = 1;

    for( int i = 0; i <= m + 1; i++ )
        a[0][i] = a[n + 1][i] = -1;

    for( int i = 0; i <= n + 1; i++ )
        a[i][0] = a[i][m + 1] = -1;

    int i = 1, j = 0;

    while( ok )
        {
            ok = 0;

            while( a[i][j + 1] == 0 )
                {
                    j++;
                    a[i][j] = nr;
                    nr++;
                    ok = 1;
                }

            while( a[i + 1][j] == 0 )
                {
                    i++;
                    a[i][j] = nr;
                    nr++;
                    ok = 1;
                }

            while( a[i][j - 1] == 0 )
                {
                    j--;
                    a[i][j] = nr;
                    nr++;
                    ok = 1;
                }

            while( a[i - 1][j] == 0 )
                {
                    i--;
                    a[i][j] = nr;
                    nr++;
                    ok = 1;
                }
        }

    /*for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= m; j++ )
                cout << a[i][j] << ' ';

            cout << endl;
        }*/
    cin >> x >> y;
    cin >> c >> d;
    cout << abs( a[c][d] - a[x][y] );

    return 0;
}
