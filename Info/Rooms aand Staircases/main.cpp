#include <bits/stdc++.h>

using namespace std;
int n, q;
string s;
int main()
{
    ios_base::sync_with_stdio( false );
    cin.tie( 0 );
    cin >> q;

    while( q-- )
        {
            cin >> n;
            cin >> s;
            int nr = 0;
            int p = 0;
            int u = 0;

            for( int i = 0; s[i]; i++ )
                {
                    if( s[i] == '1' )
                        {
                            u = i + 1;

                            if( p == 0 )
                                p = i + 1;
                        }
                }

            int c1, c2;
            c1 = u * 2;

            if( p == 0 )
                c2 = n;
            else
                c2 = ( n - p + 1 ) * 2;

            cout << max( c1, c2 ) << '\n';
        }

    return 0;
}
