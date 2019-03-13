#include <bits/stdc++.h>
using namespace std;
int q, n;
string s;
int main()
{
    cin >> q;

    for( int i = 1; i <= q; i++ )
        {
            cin >> n >> s;

            if( n == 2 && s[0] >= s[1] )
                cout << "NO" << '\n';
            else if( n == 2 )
                cout << "YES" << '\n' << 2 << '\n' << s[0] << ' ' << s[1] << '\n';
            else
                cout << "YES" << '\n' << 2 << '\n' << s[0] << ' ' << s.substr( 1 ) << '\n';
        }

    return 0;
}
