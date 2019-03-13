#include <bits/stdc++.h>
using namespace std;
ifstream fin( "sir9.in" );
ofstream fout( "sir9.out" );
const int MOD = 20173333;
int fact[100010];
int dp[3][100010];
int n, x, cer;
long long fpw( long long baza, long long exp )
{
    long long r = 1;

    while( exp > 0 )
        {
            if( exp % 2 == 1 )
                r = ( r * baza ) % MOD;

            baza = ( baza * baza ) % MOD;
            exp /= 2;
        }

    return r % MOD;
}
long long imod( long long nr )
{
    return fpw( nr, MOD - 2 );
}
long long combinari( long long n, long long k )
{
    return ( ( fact[n] * imod( fact[n - k] ) ) % MOD * imod( fact[k] ) ) % MOD;
}
int main()
{
    fin >> cer >> n >> x;
    fact[0] = 1;

    for( int i = 1; i <= 100000; i++ )
        fact[i] = i * fact[i - 1];

    if( cer == 1 )
        {
            dp[1][1] = 1;

            for( int i = 2; i <= n; i++ )
                for( int k = 1; k <= x; k++ )
                    dp[i % 2][k] = ( dp[( i - 1 ) % 2][k - 1] + dp[( i - 1 ) % 2][k] ) % MOD;

            fout << dp[n % 2][x] % MOD;
            // fout << combinari( n - 1, x - 1 );
            return 0;
        }

    dp[1][1] = 1;
    dp[1][0] = 1;

    for( int i = 2; i <= n + 1; i++ )
        for( int j = max( 1, i - x ); j < i; j++ )
            {
                dp[1][i] += dp[1][j];
                dp[1][i] %= MOD;
            }

    fout << dp[1][n + 1];
    return 0;
}
