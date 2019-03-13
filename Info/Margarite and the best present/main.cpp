#include <bits/stdc++.h>
using namespace std;
int n, l, r;
int sum( int n )
{
    if( n % 2 == 0 )
        return n / 2;
    else
        return ( n - 1 ) / 2 - n;
}
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> l >> r;
            cout << sum( r ) - sum( l - 1 ) << endl;;
        }

    return 0;
}
