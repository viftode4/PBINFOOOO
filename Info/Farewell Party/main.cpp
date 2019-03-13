#include <bits/stdc++.h>
using namespace std;
int n, x, nr, sol[100005], cnt = 1;
vector<int> a[100005];
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> x;
            a[n - x].push_back( i );
        }

    for( int i = 1; i <= n; i++ )
        {
            int l = a[i].size();

            if( l % i == 0 )
                {
                    nr = 0;

                    for( int j = 0; j < l; j++ )
                        {
                            nr++;
                            sol[a[i][j]] = cnt;

                            if( nr == i )
                                {
                                    nr = 0;
                                    cnt++;
                                }
                        }
                }
            else
                {
                    cout << "Impossible";
                    return 0;
                }
        }

    cout << "Possible" << endl;

    for( int i = 1; i <= n; i++ )
        cout << sol[i] << ' ';

    return 0;
}
