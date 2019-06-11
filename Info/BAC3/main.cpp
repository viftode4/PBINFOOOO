///ASTA E PROBLEMA 5
#include <iostream>
using namespace std;
int a[25][25], n, m, i, j;
int main()
{
    cin >> n >> m;

    for( i = 1; i <= n; i++ )
        for( j = 1; j <= m; j++ )
            a[i][j] = max( i, j );

    for( i = 1; i <= n; i++ )
        {
            for( j = 1; j <= m; j++ )
                cout << a[i][j] << ' ';

            cout << endl;
        }

    return 0;
}
