#include <bits/stdc++.h>
using namespace std;
int n;
int c[100005];
int x, y;
vector<int>sol;
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> x >> y;

            if( y == 0 )
                {
                    if( x >= 0 )
                        c[x] = 1;

                    c[i] = 1;
                }
        }

    for( int i = 1; i <= n; i++ )
        if( !c[i] )
            sol.push_back( i );

    if( sol.size() == 0 )
        cout << -1;
    else
        for( auto it : sol )
            cout << it << ' ';

    return 0;
}
