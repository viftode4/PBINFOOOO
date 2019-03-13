#include <bits/stdc++.h>
using namespace std;
int n, x, y, z, nr;
int main()
{
    cin >> n >> x >> y;

    if( x > y )
        cout << n;
    else
        {
            for( int i = 1; i <= n; i++ )
                {
                    cin >> z;

                    if( z <= x )
                        nr++;
                }

            cout << ( nr + 1 ) / 2;
        }

    return 0;
}
