#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin ( "xxx.in" );
ofstream fout ( "xxx.in" );
void fast()
{
    cin.tie ( 0 );
    ios_base::sync_with_stdio ( 0 );
}
int n, g;
int w[5005];
int p[5005];
int dp[2][10005];
int main()
{
    fast();
    cin >> n >> g;

    for ( int i = 1; i <= n; i++ )
        cin >> p[i] >> w[i];

    for ( int i = 1; i <= n; i++ )
        for ( int k = 1; k <= g; k++ )
            if ( k >= w[i] )
                dp[i % 2][k] = max ( dp[ ( i - 1 ) % 2][k], dp[ ( i - 1 ) % 2][k - w[i]] + p[i] );
            else
                dp[i % 2][k] = dp[ ( i - 1 ) % 2][k];

    cout << dp[n % 2][g];
    return 0;
}
