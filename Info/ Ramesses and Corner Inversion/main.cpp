#include <bits/stdc++.h>
using namespace std;
int n, m, nr1;
int a[510][510];
int b[510][510];
int dif[510][510];
int main()
{
    cin >> n >> m;

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            cin >> a[i][j];

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            cin >> b[i][j];

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            if( a[i][j] != b[i][j] )
                {
                    dif[i][j] = 1;
                    nr1++;
                }

    cout << endl;

    for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= m; j++ )
                cout << dif[i][j] << ' ';

            cout << endl;
        }

    cout << nr1 << ' ' << n*m - nr1;
    return 0;
}
