#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
#define INF LLONG_MAX
using namespace std;
ifstream fin( "scmax.in" );
ofstream fout( "scmax.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
int n;
ll a[100005];
ll dp[100005];
ll best[100005], v = 0;
vector<ll>sol;
ll ok( ll pos, ll x )
{
    if( best[pos] >= x )
        return 0;

    return 1;
}
ll cauta( ll x )
{
    ll  l = 0, r = v + 1;

    while( r - l > 1 )
        {
            ll mid = ( l + r ) / 2;

            if( ok( mid, x ) )
                l = mid;
            else
                r = mid;
        }

    return r;
}
int main()
{
    fast();
    fin >> n;

    for( int i = 1; i <= n; i++ )
        fin >> a[i];

    best[1] = a[1];
    dp[1] = 1;
    v = 1;

    for( int i = 2; i <= n; i++ )
        {
            ll pos = cauta( a[i] );

            if( best[pos] == 0 )
                best[pos] = a[i];

            dp[i] = pos;
            best[pos] = min( best[pos], a[i] );
            v = max( v, pos );
        }

    fout << v << '\n';

    for( int i = n; i >= 1 && v > 0; i-- )
        if( v == dp[i] )
            {
                sol.pb( a[i] );
                v--;
            }

    reverse( sol.begin(), sol.end() );

    for( auto it : sol )
        fout << it << ' ';

    return 0;
}
