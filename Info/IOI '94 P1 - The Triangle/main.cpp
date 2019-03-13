#include <iostream>
using namespace std;
int n;
int a[105][105];
int dp[2][105];
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= i; j++ )
                cin >> a[i][j];
        }


    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= n; j++ )
            dp[i % 2][j] = a[i][j] + max( dp[( i - 1 ) % 2][j], dp[( i - 1 ) % 2][j - 1] );

    int sm = 0;

    for( int i = 1; i <= n; i++ )
        sm = max( sm, dp[n % 2][i] );

    cout << sm;
    return 0;
}
