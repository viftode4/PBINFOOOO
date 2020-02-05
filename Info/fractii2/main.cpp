#include <bits/stdc++.h>
using namespace std;
ifstream fin( "fractii2.in" );
ofstream fout( "fractii2.out" );
int cer, n;
int a[2020];
int dp[2020];
int main()
{
    fin >> cer >> n;

    if( cer == 1 )
        {
            int p = 1;
            a[1] = 0;

            for( int i = 2; i <= n; i++ )
                {
                    a[i - 1] = a[i - 1] + 1;
                    a[i] = a[i - 1];
                }

            for( int i = 1; i <= n; i++ )
                fout << a[i] << ' ';
        }

    if( cer == 2 )
        {
            dp[1] = 1;
            dp[2] = 1;

            for( int i = 3; i <= n; i++ )
                {
//                    dp[i] = dp[i - 1];

                    for( int j = 1; ( 1 << j ) <= i; j++ )
                        {
                            if( ( 1 << j ) == i )
                                dp[i]++;

                            dp[i] += dp[( 1 << j )];
                        }
                }

            for( int i = 1; i <= n; i++ )
                fout << dp[i] << '\n';

            //fout << dp[n];
        }

    return 0;
}
