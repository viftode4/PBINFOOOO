#include <bits/stdc++.h>
using namespace std;
int n;
int a[100010];
int gcd ( int a, int b )
{
    int r = 0;

    while( b )
        {
            r = a % b;
            a = b;
            b = r;
        }

    return a;
}
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        cin >> a[i];

    int x = 0;

    for( int i = 1; i <= n / 2; i++ )
        x = gcd( x, abs( a[i] - a[n - i + 1] ) );

    if( x == 0 )
        cout << -1;
    else
        cout << x;

    return 0;
}
