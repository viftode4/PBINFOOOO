#include <iostream>
using namespace std;
int n, a[1001], i, poz, elmax, j;
int main()
{
    cin >> n;

    for( i = 1; i <= n; i++ )
        {
            cin >> a[i];

            if( a[i] > elmax )
                {
                    elmax = a[i];
                    poz = i;
                }
        }

    for( i = 1; i < poz - 1; i++ )
        for( j = i + 1; j <= poz - 1; j++ )
            if( a[j] < a[i] )
                swap( a[j], a[i] );

    for( i = poz + 1; i < n; i++ )
        for( j = i + 1; j <= n; j++ )
            if( a[j] > a[i] )
                swap( a[j], a[i] );

    for( i = 1; i <= n; i++ )
        cout << a[i] << ' ';

    return 0;
}
