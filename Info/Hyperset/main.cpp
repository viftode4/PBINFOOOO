#include <bits/stdc++.h>
using namespace std;
int n, k, nr;
string a[1510];
map<string, int>m;
char which( char a, char b )
{
    if( a == 'S' && b == 'S' )
        return 'S';

    if ( a == 'T' && b == 'T' )
        return 'T';

    if ( a == 'E' && b == 'E' )
        return 'E';

    if( a != 'S' && b != 'S' )
        return 'S';

    if( a != 'T' && b != 'T' )
        return 'T';

    if( a != 'E' && b != 'E' )
        return 'E';
}
int main()
{
    cin >> n >> k;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a[i];
            m[a[i]]++;
        }

    for( int i = 1; i < n; i++ )
        for( int j = i + 1; j <= n; j++ )
            {
                string s = "";

                for( int t = 0; t < k; t++ )
                    s += which( a[i][t], a[j][t] );

                //cout << a[i] << ' ' << a[j] << ' ' << s << '\n';

                if( m[s] != 0 )
                    {
                        //cout << a[i] << ' ' << a[j] << ' ' << s << '\n';
                        nr++;
                    }
            }

    cout << nr / 3;
    return 0;
}
