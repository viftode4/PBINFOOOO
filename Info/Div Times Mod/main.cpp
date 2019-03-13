#include <bits/stdc++.h>
using namespace std;
int n, k, x;
int main()
{
    cin >> n >> k;
    x = INT_MAX;

    for( int i = 1; i < k; i++ )
        if( n % i == 0 )
            x = min( x, n / i * k + i );

    cout << x;
    return 0;
}
