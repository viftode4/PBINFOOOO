#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, d;
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a >> b >> c >> d;
            int s1 = min( a, b ), s2 = max( c, d );

            if( s1 == s2 )
                s2--;

            cout << s1 << ' ' << s2 << endl;
        }

    return 0;
}
