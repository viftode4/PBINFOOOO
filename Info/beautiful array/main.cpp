#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, x, a[300006], sol;
ll dp[300006][3];
int main()
{
    cin >> n >> x;

    for( int i = 1; i <= n; i++ )
        cin >> a[i];

    // 0 numai aduni
    // 1 aduni cu inmultitul lui x de la un punct
    // 2 ai terminat de inmultit si aduni
    // nu stiu de ce merge asta :|
    for( int i = 1; i <= n; i++ )
        {
            dp[i][0] = max( dp[i - 1][0], 0LL ) + a[i];
            dp[i][1] = max( {dp[i - 1][1], dp[i - 1][0], 0LL} ) + a[i] * x;
            dp[i][2] = max( {dp[i - 1][1], dp[i - 1][2], 0LL} ) + a[i];

            sol = max( {sol, dp[i][0], dp[i][1], dp[i][2] } );
        }

    cout << sol;
    return 0;
}
