#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long n, k, m;
long long a[2010][2010];
int main()
{
    cin >> n >> m >> k;

    for( int i = 1; i <= n; i++ )
        for( int j = 0; j <= k; j++ )
            if( j == 0 )
                a[i][j] = m % MOD;
            else
                a[i][j] = ( a[i - 1][j] + ( a[i - 1][j - 1] * ( m - 1 ) ) % MOD ) % MOD;

    /*for( int i = 1; i <= n; i++ )
        {
            for ( int j = 0; j <= k; j++ )
                cout << a[i][j] << ' ';

            cout << endl;
        }
    */
    cout << a[n][k];
    return 0;
}
