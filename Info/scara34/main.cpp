#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "scara3.in" );
ofstream fout ( "scara3.out" );
int n;
int k;
int apa[1300], monster[1300];
int dp[1300], cost[1300];
int main()
{
    fin >> n;
    fin >> k;

    while ( k )
        {
            k--;
            int x, y;
            fin >> x >> y;
            apa[x] = y;
        }

    fin >> k;

    while ( k )
        {
            k--;
            int x, y;
            fin >> x >> y;
            monster[x] = y;
        }

    for ( int i = 1; i <= n; i++ )
        cost[i] = dp[i] = INT_MAX;

    for ( int i = 1; i <= n; i++ )
        {
            int x = INT_MAX, cx = INT_MAX, y = INT_MAX, cy = INT_MAX, z = INT_MAX, cz = INT_MAX;

            if ( x >= dp[i - 1] + 1 )
                {
                    if( x == dp[i - 1] + 1 )
                        cx = min( cx, cost[i - 1] );
                    else
                        cx = cost[i - 1];

                    x = dp[i - 1] + 1;
                }

            for ( int j = 1; j < i; j++ )
                {
                    if ( apa[j] >= i - j )
                        {
                            if ( y >= dp[j] + 1 )
                                {
                                    if( y == dp[j] + 1 )
                                        cy = min( cy, cost[j] );
                                    else
                                        cy = cost[j];

                                    y = dp[j] + 1;
                                }
                        }

                    if ( 2 * monster[j] >= i - j )
                        {
                            if ( z >= dp[j] + 1 )
                                {
                                    if( z == dp[j] + 1 )
                                        cz = min( cz, cost[j] + ( i - j + 1 ) / 2 );
                                    else
                                        cz = cost[j] + ( i - j + 1 ) / 2;

                                    z = dp[j] + 1;
                                }
                        }
                }

            dp[i] = min ( {x, y, z} );

            if ( dp[i] == x )
                cost[i] = min ( cost[i], cx );

            if ( dp[i] == y )
                cost[i] = min ( cost[i], cy );

            if ( dp[i] == z )
                cost[i] = min ( cost[i], cz );
        }

    fout << dp[n] << ' ' << cost[n];
    return 0;
}
