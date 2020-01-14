#include <bits/stdc++.h>
using namespace std;
long long  n, m;
long long  a[200005];
long long  s[200005];
long long dp[200005];
int main()
{
    cin >> n >> m;

    for( int i = 1; i <= n; i++ )
        cin >> a[i];

    sort( a + 1, a + n + 1 );

    for( int i = 1; i <= n; i++ )
        s[i] = s[i - 1] + a[i];

    for( int i = 1; i <= m; i++ )
        dp[i] = s[i];

    for( int i = m + 1; i <= n; i++ )
        dp[i] = dp[i - m] + s[i];


    for( int i = 1; i <= n; i++ )
        cout << dp[i] << ' ';

    //dp[1] = a[1];

    return 0;
}
