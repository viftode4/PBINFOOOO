#include <bits/stdc++.h>
using namespace std;
ifstream fin( "blis.in" );
ofstream fout( "blis.out" );
#define nd second
#define st first
#define pb push_back
#define mp make_pair
string s;
int n, k;
int dp[100005];
vector<pair<int, int>>update[100005];
int main()
{
    fin >> k;
    fin >> s;
    n = s.size();
    int v = 0;
    int mask = ( 1 << k ) - 1, big;
    big = 0;

    for( int i = 0; i < n; i++ )
        {
            v = ( v << 1 ) + ( s[i] == '1' );
            v = v & mask;
            big = max( big, v );
        }

    fout << big << '\n';

    for( int i = 1; i <= n; i++ )
        dp[i] = big;

    for( int i = 0; i < n; i++ )
        {
            v = 0;

            for( int j = 0; j <= min( k, n - i ); j++ )
                {
                    v = ( v << 1 ) + ( s[i + j] == '1' );
                    int l = 0, r = n;

                    while( r - l > 1 )
                        {
                            int mid = ( l + r ) / 2;

                            if( dp[mid] > v )
                                r = mid;
                            else
                                l = mid ;
                        }

                    if( dp[l] < v )
                        update[i + j].pb( mp( l + 1, v ) );
                }

            for( auto it : update[i] )
                dp[it.st] = min( dp[it.st], it.nd );

        }

    int R;

    for( R = 0; dp[R] != big; ++R );

    fout << R;
    return 0;
}
