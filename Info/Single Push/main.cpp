#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005];
int b[100005];
int c[100005];
int main()
{
    cin >> t;

    while( t-- )
        {
            cin >> n;

            for( int i = 1; i <= n; i++ )
                cin >> a[i];

            for( int i = 1; i <= n; i++ )
                cin >> b[i];

            int ok = 1;

            for( int i = 1; i <= n; i++ )
                {
                    c[i] = b[i] - a[i];

                    if( c[i] < 0 )
                        ok = 0;

                }

            int f = 0, nr = 0;

            for( int i = 1; i <= n; i++ )
                {
                    if( c[i] && nr==0 )
                        {
                            nr = c[i];
                            continue;
                        }

                    if( c[i] != nr && c[i] != 0 )
                        {
                            ok = 0;
                            break;
                        }

                    if( c[i] == 0 && f == 0 && nr != 0 )
                        {
                            f = 1;
                            continue;
                        }

                    if( f == 1 && c[i] )
                        {
                            ok = 0;
                            break;
                        }
                }

            if( ok )
                cout << "YES\n";
            else
                cout << "NO\n";
        }

    return 0;
}
