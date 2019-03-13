#include <bits/stdc++.h>
using namespace std;
const int NN = 1.5e7;
int n, a[300010], cmmdc, x, r, c[NN + 10], prime[NN + 10], nmax, lg, lgmax;
void ciur()
{
    prime[1] = 1;

    for ( int i = 2; i <= NN; i++ )
        prime[i] = i;

    for ( int i = 4; i <= NN; i += 2 )
        prime[i] = 2;

    for ( int i = 3; i * i <= NN ; i++ )
        if ( prime[i] == i )
            for ( int j = i * i; j <= NN; j += i )
                if ( prime[j] == j )
                    prime[j] = i;
}
int main()
{
    cin >> n;
    cin >> a[1];
    cmmdc = a[1];
    nmax = a[1];
    ciur();

    for( int i = 2; i <= n; i++ )
        {
            cin >> x;
            a[i] = x;
            nmax = max( nmax, x );

            while( x != 0 )
                {
                    r = cmmdc % x;
                    cmmdc = x;
                    x = r;
                }
        }

    for( int i = 1; i <= n; i++ )
        {
            a[i] = a[i] / cmmdc;
            int el = a[i];

            while( el > 1 )
                {
                    int x = prime[el];
                    c[x]++;
                    lgmax = max( lgmax, c[x] );

                    while( el % x == 0 )
                        el = el / x;
                }
        }

    if( lgmax == 0 )
        cout << -1;
    else
        cout << n - lgmax;

    return 0;
}
