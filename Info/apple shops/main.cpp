#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n, k, x;
int a[100010];
int ok( ull nr )
{
    ull nrk = 0;

    for( int i = 1; i <= n; i++ )
        {
            ull j = nr - a[i];
            j = j / x;
            j++;
            nrk += j;
        }

    if( nrk > k )
        return 1;

    return 0;
}
int main()
{
    cin >> n >> k >> x;

    for( int i = 1; i <= n; i++ )
        cin >> a[i];

    ull l = 1, r = 999999999;

    while( l <= r )
        {
            int m = ( l + r ) / 2;

            if( ok( m ) )
                r = m;

            else
                l = m + 1;
        }

    cout << l;
    return 0;
}
