#include <bits/stdc++.h>
using namespace std;
int n;
char a[100][100];
int ok( int i, int j )
{
    if( a[i][j] == '#' || a[i + 1][j] == '#' || a[i][j + 1] == '#' || a[i - 1][j] == '#' || a[i][j - 1] == '#' )
        return 0;

    return 1;
}
void fil( int i, int j )
{
    a[i][j] = '#';
    a[i + 1][j] = '#';
    a[i][j + 1] = '#';
    a[i - 1][j] = '#';
    a[i][j - 1] = '#';
}
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= n; j++ )
            cin >> a[i][j];

    for( int i = 2; i < n; i++ )
        for( int j = 2; j < n; j++ )
            if( ok( i, j ) )
                fil( i, j );

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= n; j++ )
            if( a[i][j] == '.' )
                {
                    cout << "NO";
                    return 0;
                }

    cout << "YES";
    return 0;
}
