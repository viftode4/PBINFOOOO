#include <bits/stdc++.h>
using namespace std;
long long n, s, d;
const int MOD = 998244353;
string a;
int main()
{
    cin >> n;
    cin >> a;

    for( int i = 0; i < n; i++ )
        if( a[i] == a[0] )
            s++;
        else
            break;

    for( int i = n - 1; i >= 0; i-- )
        if( a[i] == a[n - 1] )
            d++;
        else
            break;

    if( a[0] != a[n - 1] )
        cout << ( s + d + 1 ) % MOD;
    else
        cout << ( s + 1 )*( d + 1 ) % MOD;

    return 0;
}
