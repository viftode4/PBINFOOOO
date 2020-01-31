#include <bits/stdc++.h>

using namespace std;

ifstream fin( "joc13.in" );
ofstream fout( "joc13.out" );
int n, k;
int a[2][5005];
int dp[2][5005];
int sp[2][5005];
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
                sp[i][j] += sp[i][j - 1]+a[i][j];
                dp[1][j] = -1e6;
                dp[2][j] = -1e6;
            }

    dp[1][1] = a[1][1];
    dp[2][1] = a[2][1];
    //afisare();

    for( int i = 2; i <= n; i++ )
        {


            for( int j = i - 1; j >max( 0, i - k ); j-- )
                {
                    dp[1][i] = max( dp[1][i], dp[1][j] + sp[1][i] - sp[1][j] );
                    dp[2][i] = max( dp[2][i], dp[2][j] + sp[2][i] - sp[2][j] );
                }

            //afisare();
            int x, y;
            x = dp[1][i];
            y = dp[2][i];
            dp[1][i] = max( y + a[1][i], dp[1][i] );
            dp[2][i] = max( x + a[2][i], dp[2][i] );

        }

    fout << dp[2][n];
    return 0;
}
