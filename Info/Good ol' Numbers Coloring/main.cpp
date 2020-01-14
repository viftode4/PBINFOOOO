#include <bits/stdc++.h>
using namespace std;
int t, r, p, s, n, nr;
char m[3000];
char sol[3000];
int main()
{
    ios_base::sync_with_stdio( false );
    cin.tie( 0 );
    cin >> t;

    while( t )
        {
            t--;
            nr = 0;
            cin >> n;
            cin >> r >> p >> s;
            cin.get();
            cin >> m;

            for( int i = 0; i < n; i++ )
                sol[i] = '0';

            for( int i = 0; i < n; i++ )
                if( m[i] == 'R' && p )
                    sol[i] = 'P', p--, nr++;
                else if( m[i] == 'P' && s )
                    sol[i] = 'S', s--, nr++;
                else if( m[i] == 'S' && r )
                    sol[i] = 'R', r--, nr++;

            if( nr < ( n + 1 ) / 2 )
                {
                    cout << "NO" << '\n';
                    continue;
                }

            cout << "YES" << '\n';

            for( int i = 0; i < n; i++ )
                {
                    if( sol[i] == '0' )
                        {
                            if( s )
                                {
                                    sol[i] = 'S';
                                    s--;
                                }
                            else if( p )
                                {
                                    sol[i] = 'P';
                                    p--;
                                }
                            else if( r )
                                {
                                    sol[i] = 'R';
                                    r--;
                                }
                        }

                    cout << sol[i];
                }

            cout << '\n';
        }

    return 0;
}
