#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int a[100005];
int main()
{
    cin >> t;

    while( t-- )
        {
            cin >> n >> x;
            string s;
            cin >> s;

            int k = 0, nr = 0;

            for( int i = 1; i <= n; i++ )
                {
                    a[i] = a[i - 1];

                    if( s[i - 1] == '0' )
                        a[i]++;
                    else
                        a[i]--;
                }

            k = a[n];

            if( x < 0 )
                {
                    k *= -1;
                    x *= -1;
                }

            if( k > 0 )
                {
                    for( int i = 1; i <= n; i++ )
                        if( a[i] >= 0 && s[i - 1] == '1' && a[i] <= x )
                            nr++;

                    cout << nr + 1 << '\n';
                }
            else if( k == 0 )
                {
                    for( int i = 1; i <= n; i++ )
                        if( a[i] == x )
                            nr++;

                    if( nr > 0 || x == 0 && nr == 0 )
                        cout << -1 << '\n';
                }
            else
                {
                    for( int i = 1; i <= n; i++ )
                        if( a[i] == x )
                            nr++;

                    cout << nr << '\n';
                }

        }

    return 0;
}
