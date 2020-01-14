#include <bits/stdc++.h>
using namespace std;
int a1, a2, k1, k2, n;
int main()
{
    cin >> a1 >> a2 >> k1 >> k2 >> n;

    if( k1 > k2 )
        {
            swap( k1, k2 );
            swap( a1, a2 );
        }

    int mini = 1e9, maxi = 0, cn = n;
    maxi = min( a1, n / k1 );
    n -= maxi * k1;
    maxi += min( a2, n / k2 );
    n = cn;

    int total = a1 + a2;
    n -= a1 * ( k1 - 1 ) + a2 * ( k2 - 1 );
    //cout << n << ' ';

    if( n <= 0 )
        {
            cout << 0 << ' ' << maxi;
            return 0;
        }

    cout << min( n, total ) << ' ' << maxi;
    return 0;
}
