#include <bits/stdc++.h>
using namespace std;
int n, m, d;
int c[1010], s = 0;
int dist[1010];
int main()
{
    cin >> n >> m >> d;

    for( int i = 1; i <= m; i++ )
        {
            cin >> c[i];
            s += c[i];
        }

    // cout << s;
    s = n - s;
    // cout << s;

    for( int i = 1; i <= m && s > 0; i++ )
        {
            dist[i] += min( s, d - 1 );
            s -= min( s, d - 1 );
        }

    //cout << s;

    if( s >= d )
        {
            cout << "NO\n";
            return 0;
        }

    cout << "YES\n";

    for( int i = 1; i <= n; i++ )
        {
            while( dist[i] )
                {
                    dist[i]--;
                    cout << 0 << ' ';
                }

            while( c[i] )
                {
                    c[i]--;
                    cout << i << ' ';
                }
        }

    while( s > 0 )
        {
            cout << 0 << ' ';
            s--;
        }

    return 0;
}
