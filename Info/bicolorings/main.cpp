#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, k;
int a[1005][2010][4];
int main()
{
    cin >> n >> k;
    a[1][1][0] = 1;
    a[1][2][1] = 1;
    a[1][2][2] = 1;
    a[1][1][3] = 1;

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= k; j++ )
            {
                //0 00
                //1 01
                //2 10
                //3 11
                a[i][j][0] += a[i - 1][j][0];
                a[i][j][0] = a[i][j][0] % MOD;
                a[i][j][0] += a[i - 1][j][1];
                a[i][j][0] = a[i][j][0] % MOD;
                a[i][j][0] += a[i - 1][j][2];
                a[i][j][0] = a[i][j][0] % MOD;
                a[i][j][0] += a[i - 1][j - 1][3];
                a[i][j][0] = a[i][j][0] % MOD;
                //
                a[i][j][1] += a[i - 1][j - 1][0];
                a[i][j][1] = a[i][j][1] % MOD;
                a[i][j][1] += a[i - 1][j][1];
                a[i][j][1] = a[i][j][1] % MOD;

                if( j >= 2 )
                    a[i][j][1] += a[i - 1][j - 2][2];

                a[i][j][1] = a[i][j][1] % MOD;
                a[i][j][1] += a[i - 1][j - 1][3];
                a[i][j][1] = a[i][j][1] % MOD;
                //
                a[i][j][2] += a[i - 1][j - 1][0];
                a[i][j][2] = a[i][j][2] % MOD;

                if( j >= 2 )
                    a[i][j][2] += a[i - 1][j - 2][1];

                a[i][j][2] = a[i][j][2] % MOD;
                a[i][j][2] += a[i - 1][j][2];
                a[i][j][2] = a[i][j][2] % MOD;
                a[i][j][2] += a[i - 1][j - 1][3];
                a[i][j][2] = a[i][j][2] % MOD;
                //
                a[i][j][3] += a[i - 1][j - 1][0];
                a[i][j][3] = a[i][j][3] % MOD;
                a[i][j][3] += a[i - 1][j][1];
                a[i][j][3] = a[i][j][3] % MOD;
                a[i][j][3] += a[i - 1][j][2];
                a[i][j][3] = a[i][j][3] % MOD;
                a[i][j][3] += a[i - 1][j][3];
                a[i][j][3] = a[i][j][3] % MOD;
            }

    long long s;
    s = ( ( ( a[n][k][0] + a[n][k][1] ) % MOD + a[n][k][2] ) % MOD + a[n][k][3] ) % MOD;

    /*for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= k; j++ )
                cout << a[i][j][0] << ' ' << a[i][j][1] << ' ' << a[i][j][2] << ' ' << a[i][j][3] << "\\";

            cout << endl;
        }*/

    cout << s << ' ';
    return 0;
}
