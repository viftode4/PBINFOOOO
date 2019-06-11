/// ASTA E 7
#include <iostream>
using namespace std;
int a[25][25], n, i, j;
int main()
{
    cin >> n;

    for( i = 1; i <= n; i++ )
        for( j = 1; j <= n; j++ )
            cin >> a[i][j];

    for( j = 1; j <= n; j++ )
        cout << a[1][j] << ' ';

    for( i = 2; i <= n; i++ )
        cout << a[i][n] << ' ';

    for( j = n - 1; j >= 1; j-- )
        cout << a[n][j] << ' ';

    for( i = n - 1; i >= 2; i-- )
        cout << a[i][1] << ' ';

    return 0;
}
