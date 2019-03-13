#include <iostream>
using namespace std;
int n, v[1001], m, d, j, i, x;
int main()
{
    cin >> n;
    m = 0;

    for( i = 1; i <= n; i++ )
        {
            cin >> x;

            if( x == 2 )
                {
                    m++;
                    v[m] = 2;
                }
            else if( x != 0 && x != 1 )
                {
                    int ok = 1;

                    for( d = 2; d * d <= x; d++ )
                        if( x % d == 0 )
                            {
                                ok = 0;
                                break;
                            }

                    if( ok == 1 )
                        {
                            m++;
                            v[m] = x;
                        }
                }
        }

    for( i = 1; i < m; i++ )
        for( j = i + 1; j <= m; j++ )
            if( v[i] > v[j] )
                swap( v[i], v[j] );

    for( i = 1; i <= m; i++ )
        cout << v[i] << ' ';

    return 0;
}
