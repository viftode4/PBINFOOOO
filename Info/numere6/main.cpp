#include <bits/stdc++.h>
using namespace std;
ifstream fin( "numere6.in" );
ofstream fout( "numere6.out" );
#define MOD 9973
int a, b, cnn;
int dp[10000];
vector<int>dvz;
int main()
{
    fin >> a >> b;

    for( int i = 1; i <= b; i++ )
        if( b % i == 0 )
            dvz.push_back( i );

    for( int i = 1; i <= 9; i++ )
        dp[i] = 1;

    int n = dvz.size();
    a--;

    while( a-- )
        {
            for( int i = n - 1; i >= 0; i-- )
                {
                    int x = dvz[i];

                    if( dp[x] )
                        for( int j = 2; j <= 9; j++ )
                            {
                                int nr = j * x;

                                if( nr > b )
                                    break;

                                dp[nr] = ( dp[nr] + dp[x] ) % MOD;
                            }
                }
        }

    fout << dp[b];
    return 0;
}
