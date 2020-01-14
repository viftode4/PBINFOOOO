#include <bits/stdc++.h>
using namespace std;
int dp[200005][2];
int a[200005], b[200005];
int n, c;
int main()
{
    cin >> n >> c;

    for( int i = 1; i < n; i++ )
        cin >> a[i];

    for( int i = 1; i < n; i++ )
        cin >> b[i];

    dp[1][0] = 0;
    dp[1][1] = c;

    for( int i = 2; i <= n; i++ )
        {
            dp[i][0] = min( dp[i - 1][0] + a[i - 1], dp[i - 1][1] + a[i - 1] );
            dp[i][1] = min( dp[i - 1][1] + b[i - 1], dp[i - 1][0] + b[i - 1] + c );
        }

    //cout << 0<<' ';

    for( int i = 1; i <= n; i++ )
        cout << min( dp[i][0], dp[i][1] ) << ' ';

    return 0;
}
