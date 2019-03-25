#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1003][1003];
int sol[1003][1003];
set<int>l[1003], c[1003];
int main()
{
    cin >> n >> m;

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            {
                cin >> a[i][j];
                l[i].insert( a[i][j] );
                c[j].insert( a[i][j] );
            }

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            {
                int posl = ( lower_bound( l[i].begin(), l[i].end(), a[i][j] ) - l[i].begin() ) + 1;
                int posc = ( lower_bound( c[j].begin(), c[j].end(), a[i][j] ) - c[j].begin() ) + 1;
                sol[i][j] = max( posl, posc ) + max( l[i].size() - posl + 1, c[j].size() - posc + 1 );
            }

    for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= m; j++ )
                cout << sol[i][j] << ' ';

            cout << '\n';
        }

    return 0;
}
