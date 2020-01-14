#include <bits/stdc++.h>
using namespace std;
long long n, cmmdc ;
int main()
{
    cin >> n;
    cmmdc = n;

    for( long long i = 2; i * i <= n; i++ )
        if( !( n % i ) )
            cmmdc = __gcd( cmmdc, __gcd( i, n / i ) );

    cout << cmmdc;

    return 0;
}
