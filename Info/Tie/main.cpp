#include <bits/stdc++.h>
using namespace std;
int n;
struct p
{
    int s, d;
} a[103];
int v[103], dp[103], nrm;
int cond( p a, p b )
{
    return a.s < b.s;
}
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        cin >> a[i].s >> a[i].d;

    sort( a + 1, a + n + 1, cond );

    for( int i = 1; i <= n; i++ )
        v[i] = a[i].d;

    for( int i = n - 1; i >= 1; i-- )
        {
            dp[i] = 1;

            for( int j = i + 1; j <= n; j++ )
                if( v[i] <= v[j] )
                    dp[i] = dp[j] + 1;

            nrm = max( dp[i], nrm );
        }

    cout << n - nrm;
    return 0;
}
