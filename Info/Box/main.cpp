#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int sol[100005];
int p[100005];
int main()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( false );
    cin >> t;

    while( t-- )
        {
            cin >> n;
            set<int>s;

            for( int i = 1; i <= n; i++ )
                {
                    cin >> p[i];
                    s.insert( i );
                }

            int ok = 1;

            for( int i = 1; i <= n; i++ )
                {

                    x = p[i];

                    if( i == 1  )
                        {
                            sol[i] = x;
                            s.erase( s.find( x ) );
                            continue;
                        }

                    auto it = s.begin();

                    if( s.find( x ) != s.end() )
                        {
                            sol[i] = x;
                            s.erase( s.find( x ) );
                        }
                    else
                        {
                            if( *it > x )
                                {
                                    ok = 0;
                                    break;
                                }
                            else
                                {
                                    sol[i] = *it;
                                    s.erase( it );
                                }
                        }
                }

            if( !ok )
                {
                    cout << -1 << '\n';
                }
            else
                {
                    for( int i = 1; i <= n; i++ )
                        cout << sol[i] << ' ';

                    cout << '\n';
                }
        }

    return 0;
}
