#include <bits/stdc++.h>
using namespace std;
int n, m, a[2001];
char c[2001][2001];
int main()
{
    cin >> n >> m;

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            {
                cin >> c[i][j];

                if( c[i][j] == '1' )
                    a[j]++;
            }

    for( int i = 1; i <= n; i++ )
        {
            bool k = 0;

            for( int j = 1; j <= m; j++ )
                if( c[i][j] == '1' && a[j] == 1 )
                    k = 1;

            if( k == 0 )
                {
                    cout << "YES";
                    return 0;
                }
        }

    cout << "NO";
    return 0;
}
