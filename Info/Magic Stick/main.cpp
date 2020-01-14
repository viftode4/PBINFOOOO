#include <bits/stdc++.h>
using namespace std;
int t;
int x, y;
int main()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( false );
    cin >> t;

    while( t-- )
        {
            cin >> x >> y;

            if( x >= y || y == 1 )
                {
                    cout << "YES" << '\n';
                    continue;
                }

            if( x == 1 && y != 1 )
                {
                    cout << "NO\n";
                    continue;
                }

            if( x <= 3&&y>3 )
                {
                    cout << "NO\n";
                    continue;
                }
            cout << "YES\n";
        }

    return 0;
}
