///ASTA E 6
#include <iostream>
using namespace std;
int a[25][25], n, m, i, j;
int main()
{
    cin >> n >> m;

    for( i = 1; i <= n; i++ )
        for( j = 1; j <= m; j++ )
            {
                int x = 2 * m * ( i - 1 ) + j * 2 - 1;
                a[i][j] = x * x;
            }

    for( i = 1; i <= n; i++ )
        {
            for( j = 1; j <= m; j++ )
                cout << a[i][j] << ' ';

            cout << endl;
        }

    return 0;
}
