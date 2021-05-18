#include <iostream>
using namespace std;
int v[1005], i, sol[1005], x, k, a, b, r, n, j;
int main()
{
    cin >> n;

    for ( i = 1; i <= n; i++ )
        cin >> v[i];

    x = v[n];

    for ( i = 1; i <= n; i++ )
        {
            a = x;
            b = v[i];

            while ( b != 0 )
                {
                    r = a % b;
                    a = b;
                    b = r;
                }

            if ( a == 1 )
                {
                    k++;
                    sol[k] = v[i];
                }
        }

    for ( i = 1; i < k; i++ )
        for ( j = i + 1; j <= k; j++ )
            if ( sol[i] < sol[j] )
                swap ( sol[i], sol[j] );

    for ( i = 1; i <= k; i++ )
        cout << sol[i] << ' ';

    return 0;
}
