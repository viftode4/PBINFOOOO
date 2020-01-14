#include <bits/stdc++.h>

using namespace std;
int q, a, b, c, d, k;
int main()
{
    ios_base::sync_with_stdio( false );
    cin.tie( 0 );
    cin >> q;

    while( q-- )
        {
            cin >> a >> b >> c >> d >> k;
            int nr1 = ( a + c - 1 ) / c;
            int nr2 = ( b + d - 1 ) / d;

            if( nr1 + nr2 <= k )
                cout << nr1 << ' ' << nr2 << '\n';
            else
                cout << -1 << '\n';

        }

    return 0;
}
