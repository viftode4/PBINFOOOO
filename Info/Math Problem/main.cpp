#include <bits/stdc++.h>
using namespace std;
int n, t;
int main()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( false );
    cin >> t;

    while( t-- )
        {
            cin >> n;
            int l = INT_MAX, r = 0;

            for( int i = 1; i <= n; i++ )
                {
                    int x, y;
                    cin >> x >> y;
                    l = min( l, y );
                    r = max( r, x );
                }

            //cout<<r<<' '<<l<<'\n';
            cout << max( 0, r - l ) << '\n';
        }

    return 0;
}
