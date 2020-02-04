#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main()
{
    cin >> n >> k;
    long long x = ( -3 * 1LL + ( sqrt( 9 + 8 * ( k + n ) ) + 0.0001 ) * 1LL ) / 2 * 1LL;
    cout << n - x;
    return 0;
}
