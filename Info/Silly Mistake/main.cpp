#include <bits/stdc++.h>
using namespace std;
int n, lg;
long long s, x;
vector<int>sol;
map<int, int>m;
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> x;
            s += x;
            lg++;

            if( x < 0 && m[x] % 2 != 0 )
                m[-1 * x]++;
            else if( x < 0 && m[x] % 2 == 0 )
                {
                    cout << -1;
                    return 0;
                }

            if( x > 0 && m[x] % 2 == 0 )
                m[-1 * x]++;

            else if( x > 0 && m[x] % 2 != 0 )
                {
                    cout << -1;
                    return 0;
                }

            if( s == 0 )
                {
                    for( auto it : m )
                        if( it.second > 1 )
                            {
                                cout << -1;
                                return 0;
                            }

                    sol.push_back( lg );
                    m.clear();
                    lg = 0;
                }
        }

    if( s )
        {
            cout << -1;
            return 0;
        }

    cout << sol.size() << '\n';;

    for( auto it : sol )
        cout << it << ' ';

    return 0;
}
