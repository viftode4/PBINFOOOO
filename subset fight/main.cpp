#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
#define MOD 1000000007
using namespace std;
ifstream fin ( "xxx.in" );
ofstream fout ( "xxx.in" );
void fast()
{
    cin.tie ( 0 );
    ios_base::sync_with_stdio ( 0 );
}
ll dp[110][110], n, a[110];
int inv ( int n, int a, int b )
{
    if ( a >= b )
        return a - b;
    else
        return n - ( a - b );
}
int main()
{
    fast();
    cin >> n;

    for ( int i = 1; i <= n; i++ )
        {
            cin >> a[i];
        }

    dp[1][1] = 1;
    a[0] = a[n];

    for ( int i = 2; i <= n; i++ )
        {
            for ( int j = 1; j <= n; j++ )
                {
                    dp[i][j] = ( dp[i][j] + ( dp[i - 1][inv ( n, j, i )] + a[i] ) % MOD ) % MOD;
                }
        }

    for ( int i = 1; i <= n; i++ )
        {
            for ( int j = 1; j <= n; j++ )
                {
                    cout << dp[i][j] << ' ';
                }

            cout << endl;
        }

    return 0;
}
