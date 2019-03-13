#include <bits/stdc++.h>
using namespace std;
int n, p;
unsigned long long f[10010];
unsigned g[10010], sum[10010];
int main()
{
    n = 1, p = 1;
    g[1] = 1;
    sum[1] = 3;
    f[1] = 1;

    for( int i = 2; i <= 10003; i++ )
        g[i] = i;

    while( n != 0 && p != 0 )
        {
            cin >> n >> p;
            f[1] = 1;

            for( int i = 2; i <= n; i++ )
                f[i] = ( f[i - 1] * g[i] ) % p;

            cout << f[n] << '\n';
        }

    return 0;
}
