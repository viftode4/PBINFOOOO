#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[510][510];
int pl( int i, int j )
{
    if( a[i][j] != a[i][j - 1] )
        return 0;

    if( a[i][j] != a[i - 1][j] )
        return 0;

    if( a[i][j] != a[i][j + 1] )
        return 0;

    if( a[i][j] != a[i + 1][j] )
        return 0;

    return 1;

}
int main()
{
    cin >> n >> m;

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            cin >> a[i][j];

    for( int i = 2; i < n; i++ )
        for( int j = 2; j < m; j++ )
            if( pl( i, j ) && a[i][j] == '*' )
                {
                    for( int k = i + 1; a[k][j] == '*' && k <= n; k++ )
                        a[k][j] = '.';

                    for( int k = i - 1; a[k][j] == '*' && k >= 1; k-- )
                        a[k][j] = '.';

                    for( int k = j - 1; a[i][k] == '*' && k >= 1; k-- )
                        a[i][k] = '.';

                    for( int k = j; a[i][k] == '*' && k <= m; k++ )
                        a[i][k] = '.';

                    break;
                }

    /* for( int i = 1; i <= n; i++ )
         {
             for( int j = 1; j <= m; j++ )
                 cout << a[i][j];
                 cout<<endl;
         }
    */
    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            if( a[i][j] == '*' )
                {
                    cout << "NO";
                    return 0;
                }

    cout << "YES";
    return 0;
}
