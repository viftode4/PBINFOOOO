#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
string s;
long long nr = 1, lg = 1;
long long dp[100005];
int main()
{
    cin >> s;
    int n = s.size();

    for( int i = 0; i < n; i++ )
        if( s[i] == 'w' || s[i] == 'm' )
            {
                cout << 0;
                return 0;
            }

    dp[0] = 1;
    dp[1] = 1;

    for ( int i = 2; i <= n; ++i )
        {
            dp[i] = dp[i - 1];

            if ( s[i - 1] == s[i - 2] && ( s[i - 1] == 'u' || s[i - 1] == 'n' ) )
                dp[i] = ( dp[i] + dp[i - 2] ) % MOD;
        }

    cout << dp[n];
    // cout << (MOD+( (MOD+( INT_MAX % MOD ))%MOD * (MOD+( INT_MAX % MOD ))%MOD )) % MOD;
    return 0;
}
