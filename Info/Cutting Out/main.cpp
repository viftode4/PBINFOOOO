#include <bits/stdc++.h>
using namespace std;
int n, k, x, m, t;
int a[200005], rez[200005];
vector<int> sol;
struct nr
{
    int n, i;
} f[200005];
int cond( nr a, nr b )
{
    return a.n < b.n;
}
int ok( int p )
{
    sol.clear();

    for( int i = t; i >= 1; i-- )
        {
            int s = k - ( int )sol.size();
            int a = f[i].n / p;
            int c = min( a, s );

            for( int j = 1; j <= c; j++ )
                sol.push_back( f[i].i );
        }

    return ( int( sol.size() ) >= k );
}
int main()
{
    cin >> k >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> x;
            a[x]++;
            m = max( m, x );
        }

    for( int i = 1; i <= m; i++ )
        if( a[i] != 0 )
            {
                f[++t].i = i;
                f[t].n = a[i];
            }

    sort( f + 1, f + t + 1, cond );
    int l = 0, r = n;

    while( r - l > 1 )
        {
            int mid = ( l + r ) / 2;

            if( ok( mid ) )
                l = mid;
            else
                r = mid;
        }

    //cout << l << ' ' << r << endl;

    if( ok( r ) )
        cout << r << ' ';
    else
        cout << l << ' ';


    return 0;
}
