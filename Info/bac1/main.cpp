///ASTA E PROBLEMA 3
#include <iostream>
using namespace std;
int a[25][25], n, i, j;
int main()
{
    cin >> n;

    for( i = 1; i <= n; i++ )
        for( j = 1; j <= n; j++ )
            if( i != j )
                a[i][j] = n - j + 1;
            else
                a[i][j] = 0;

    for( i = 1; i <= n; i++ )
        {
            for( j = 1; j <= n; j++ )
                cout << a[i][j] << ' ';

            cout << endl;
        }

    return 0;
}
