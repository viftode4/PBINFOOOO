#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[510][510];
long long b[510][510];
set <long long> s[2][1010];
int main()
{
    cin >> n >> m;
    cin.tie( NULL );
    ios_base::sync_with_stdio();

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            {
                cin >> a[i][j];
                s[0][i + j].insert( a[i][j] );
            }

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            {
                cin >> b[i][j];
                s[1][i + j].insert( b[i][j] );
            }

    for( long long i = 1; i <= n + m; i++ )
        {
            if( s[1][i] != s[0][i] )
                {
                    cout << "NO";
                    return 0;
                }
        }

    cout << "YES";
    return 0;
}
