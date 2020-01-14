#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define pb push_back
#define mp make_pair
int m, n, k, t;
int a[200005];
int l[200005];
int r[200005];
int d[200005];
int ok( int x )
{
    vector <pair<int, int>>trap;
    int mn = INT_MAX;

    for( int i = 1; i <= x; i++ )
        mn = min( mn, a[i] );

    for( int i = 1; i <= k; i++ )
        if( d[i] > mn )
            trap.pb( mp( l[i], r[i] ) );

    int cat = 0, last = 0;
    last = 0;

    for( auto it : trap )
        if( last >= it.st )
            {
                cat += max( 0, it.nd - last );
                last = max( last, it.nd );
            }
        else
            {
                cat += it.nd - it.st + 1;
                last = it.nd;
            }

    cat = 2 * cat + n + 1;
    return cat <= t;
}
int main()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( false );
    cin >> m >> n >> k >> t;

    for( int i = 1; i <= m; i++ )
        cin >> a[i];

    sort( a + 1, a + m + 1, greater<int>() );

    for( int i = 1; i <= k; i++ )
        cin >> l[i] >> r[i] >> d[i];

    int l = 0, r = m + 1;

    while( r - l > 1 )
        {
            int mid = ( l + r ) / 2;

            if( ok( mid ) )
                l = mid;
            else
                r = mid;
        }

    cout << l;
    return 0;
}
