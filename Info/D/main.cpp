#include <iostream>
using namespace std;
long long n, sol;
const int MOD = 998244353;
int main()
{
    cin >> n;
    sol = 1;

    for( int i = 1; i <= n; i++ )
        sol = ( sol * i ) % MOD;

    sol = sol * n % MOD - n + 1;
    cout<<sol;
    return 0;

}
