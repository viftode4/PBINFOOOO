#include <bits/stdc++.h>
using namespace std;
ifstream fin( "100m.in" );
ofstream fout( "100m.out" );
#define ll long long
const ll MOD = 666013;
int dp[4010][4010];
int n, fact[5010], sum;
int main()
{
    fin >> n;
    fact[0] = 1;

    for( int i = 1; i <= n; i++ )
        fact[i] = ( fact[i - 1] * i ) % MOD;

    for( int i = 1; i <= n; i++ )
        dp[i][1] = 1;

    for( int i = 1; i <= n; i++ )
        for( int j = 2; j <= i; j++ )
            dp[i][j] = ( dp[i - 1][j - 1] + ( j * dp[i - 1][j] ) % MOD ) % MOD;

    for( int i = 1; i <= n; i++ )
        {
            sum = ( sum + ( dp[n][i] * fact[i] ) % MOD ) % MOD;
        }

    fout << sum;
}
