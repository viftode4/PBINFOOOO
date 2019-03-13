#include <bits/stdc++.h>
using namespace std;
int n, m, s, smin = INT_MAX;
int a[3001];
int d[3001][3001];
int caut( int x )
{
    int l = 0, r = n + 1, mid;

    while( r - l > 1 )
        {
            mid = ( l + r ) / 2;

            if( a[mid] > x )
                r = mid;
            else
                l = mid;
        }

    return r;
}
int main()
{
    cin >> n >> m;

    for( int i = 1; i <= n; i++ )
        cin >> a[i];

    sort( a + 1, a + n + 1 );

    for( int i = 1; i <= m; i++ )
        {
            for( int j = 1; j <= m; j++ )
                d[i][j] = min( abs( i - j ), m - abs( i - j ) );
        }

    for( int i = 1; i <= m; i++ )
        {
            int x = caut( i );
            cout << x << ' ';
            int l = i;
            int r = i + 1;

            if( l == 0 )
                l = m;
            else if( r == m + 1 )
                r = 1;

        }

    cout << smin;
    return 0;
}
