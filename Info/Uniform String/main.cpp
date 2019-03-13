#include <bits/stdc++.h>
using namespace std;
int n;
int x, y;
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> x >> y;
            char c = 0;
            int z = x / y;
            string s = "";

            for( int j = 0; j <= x - ( x % y ) - 1; j++ )
                {
                    c = ( j / z + 'a' );
                    s = s + c;
                }

            for( int j = x - ( x % y ); j < x; j++ )
                s += c;

            cout << s << endl;
        }

    return 0;
}
