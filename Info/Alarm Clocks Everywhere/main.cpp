#include <bits/stdc++.h>
using namespace std;
long long n, m, x;
long long a[300005];
long long dif[300005];
long long p[300005];
int main()
{
    cin >> n >> m;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a[i];
            dif[i] = a[i] - a[i - 1];
        }

    for( int i = 2; i <= n; i++ )
        x = __gcd( dif[i], x );

    for( int i = 1; i <= m; i++ )
        {
            cin >> p[i];

            if( x % p[i] == 0 || p[i] == 1 )
                {
                    cout << "YES\n" << a[1] << ' ' << i;
                    return 0;
                }
        }

    cout << "NO";
    return 0;
}
