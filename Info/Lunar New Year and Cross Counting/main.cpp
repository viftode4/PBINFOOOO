#include <bits/stdc++.h>
using namespace std;
int n, nr;
char a[510][510];
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= n; j++ )
            cin >> a[i][j];

    for( int i = 2; i <= n - 1; i++ )
        for( int j = 2; j <= n - 1; j++ )
            {
                if( a[i][j] == 'X' && a[i - 1][j - 1] == 'X' && a[i - 1][j + 1] == 'X' && a[i + 1][j - 1] == 'X' && a[i + 1][j + 1] == 'X' )
                    nr++;
            }

    cout << nr;
    return 0;
}
