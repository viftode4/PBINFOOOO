#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int nr1, nr2;
int main()
{
    cin >> t;
    cin.tie( NULL );

    while( t )
        {
            cin >> n;
            cin >> s;
            nr1 = nr2 = 0;

            if( n == 1 )
                {
                    cout << 0 << '\n';
                    t--;
                    continue;
                }
            else
                for( int i = 0; s[i]; i++ )
                    if( s[i] == '<' )
                        nr1++;
                    else
                        break;

            for( int i = n - 1; i >= 0; i-- )
                if( s[i] == '>' )
                    nr2++;
                else
                    break;

            cout << min( nr1, nr2 ) << '\n';
            t--;
        }

    return 0;
}
