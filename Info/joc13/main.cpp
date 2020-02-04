#include <bits/stdc++.h>

using namespace std;

ifstream fin( "joc13.in" );
ofstream fout( "joc13.out" );
int n, k;
int a[5][5005];
int dp[5][5005];
int sp[5][5005];
void afisare()
{
    for( int j = 1; j <= 2; j++ )
        {
            for( int i = 1; i <= n; i++ )
                fout << dp[j][i] << ' ';

            fout << endl;
        }
}
int main()
{
    fin >> n >> k;

    for( int i = 1; i <= 2; i++ )
        for( int j = 1; j <= n; j++ )
            {
                fin >> a[i][j];

                if( i == 2 && j == 1 )
                    sp[i][j] = a[1][j];

                sp[i][j] += sp[i][j - 1] + a[i][j];
                dp[1][j] = -1e6;
                dp[2][j] = -1e6;
            }

    for( int i = 1; i <= k; i++ )
        {
            dp[1][i] = sp[1][i];
            dp[2][i] = sp[2][i];
        }

    for( int i = 2; i <= n; i++ )
        {
            for( int j = i + 1 ; j <= min( n, i + k - 1 ); j++ )
                {
                    int x, y;
                    x = dp[2][i] + sp[1][j] - sp[1][i - 1];
                    y = dp[1][i] + sp[2][j] - sp[2][i - 1];
                    dp[1][j] = max( dp[1][j], x );
                    dp[2][j] = max( dp[2][j], y );
                }
        }

    fout << max( dp[2][n], dp[1][n] + a[2][n] );
    return 0;
}
