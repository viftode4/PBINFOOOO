#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "xxx.in" );
ofstream fout( "xxx.in" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
int n, k;
int a[200005];
int ok( ll x )
{
    ll ans = 0;

    for( int i = n / 2 + 1; i <= n; i++ )
        ans += max( 0LL, x - a[i] );

    if( ans <= k )
        return 1;

    return 0;
}

int main()
{
    fast();
    cin >> n >> k;

    for( int i = 1; i <= n; i++ )
        cin >> a[i];

    sort( a + 1, a + n + 1 );
    ll l = a[n / 2 + 1], r = 1e10 ;

    while( r - l > 1 )
        {
            ll mid = ( l + r ) / 2;

            if( ok( mid ) )
                l = mid;
            else
                r = mid;
        }

    cout << l;
    return 0;
}
