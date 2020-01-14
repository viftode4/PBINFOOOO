#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n, m;
vector<int>g[100005];
int use[100005];
int q[100005], t, T, nr;
int main()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( false );
    cin >> n >> m;

    for( int i = 1; i <= m; i++ )
        {
            int x, y;
            cin >> x >> y;
            g[x].pb( y );
            g[y].pb( x );
        }

    set<int>s;

    for( int i = 1; i <= n; i++ )
        s.insert( i );

    for( int i = 1; i <= n; i++ )
        if( s.count( i ) )
            {
                s.erase( i );
                q[t++] = i;
                nr++;

                for( int j = 0; j < t; j++ )
                    {
                        int u = q[j];
                        ++T;

                        for( auto it : g[u] )
                            use[it] = T;

                        vector<int>v;

                        for( auto it : s )
                            if( use[it] != T )
                                {
                                    v.pb( it );
                                }

                        for( auto it : v )
                            {
                                q[t++] = it;
                                s.erase( it );
                            }
                    }

            }

    cout << nr - 1;
    return 0;
}
