#include <bits/stdc++.h>
using namespace std;
ifstream fin( "cmlsc.in" );
ofstream fout( "cmlsc.out" );
int n, m;
int a[1050], b[1050], dp[1050][1050];
int main()
{
    fin >> n >> m;

    for( int i = 1; i <= n; i++ )
        fin >> a[i];

    for( int j = 1; j <= m; j++ )
        fin >> b[j];

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            if( a[i] == b[j] )
                dp[i][j] += 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max( dp[i - 1][j], dp[i][j - 1] );

    /* for( int i = 1; i <= n; i++ )
         {
             for( int j = 1; j <= m; j++ )
                 fout << dp[i][j] << ' ';

             fout << endl;
         }
    */
    fout << dp[n][m];

    return 0;
}
