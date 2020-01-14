#include <bits/stdc++.h>
using namespace std;
int n, a[200005], t;
int last[200005];
int main()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( false );

    cin >> t;

    while( t-- )
        {
            cin >> n;

            int lg = n + 1;
            int ok = 0;

            for( int i = 1; i <= n; i++ )
                last[i] = 0;

            for( int i = 1; i <= n; i++ )
                {
                    cin >> a[i];

                    if( last[a[i]] )
                        {
                            lg = min( i - last[a[i]] + 1, lg );
                            ok = 1;
                        }


                    last[a[i]] = i;
                }

            if( !ok )
                cout << -1 << '\n';
            else
                cout << lg << '\n';
        }

    return 0;
}
