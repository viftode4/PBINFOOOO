#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105][510], s[105][510], dp[105][510];
vector<int> v;
vector<int>::reverse_iterator t;
int main()
{
    cin >> n >> m;

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            {
                cin >> a[i][j];
                int x = a[i][j];
                s[i][j] = s[i][j - 1] + x;
            }

    for( int i = 1; i <= m; i++ )
        dp[1][i] = a[1][i];

    for( int i = 2; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            {
                dp[i][j] = dp[i - 1][1] + s[i][j];

                for( int k = 2; k <= j; k++ )
                    dp[i][j] = min( dp[i][j], dp[i - 1][k] +  s[i][j] - s[i][k - 1] );

                for( int k = j + 1; k <= m; k++ )
                    dp[i][j] = min( dp[i][j], dp[i - 1][k] +  s[i][k] - s[i][j - 1] );
            }

    int rez = INT_MAX, k = 0;

    for( int i = 1; i <= m; i++ )
        if( rez > dp[n][i] )
            {
                rez = dp[n][i];
                k = i;
            }


    int i = n - 1;
    int j = k;
    v.push_back( k );
    v.push_back( k );

    while( i > 1 )
        {
            if( dp[i][j + 1] < dp[i][j] )
                {
                    while( dp[i][j + 1] < dp[i][j] )
                        {
                            j++;
                            v.push_back( j );
                        }

                    v.push_back( j );
                    i--;
                }
            else
                {
                    while( dp[i][j + 1] < dp[i][j] )
                        {
                            j++;
                            v.push_back( j );
                        }

                    v.push_back( j );
                    i--;
                }
        }

    for( t = v.rbegin(); t != v.rend(); t++ )
        cout << *t << ' ';

    return 0;
}
