#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
int t, n;
int a[200005];
int main()
{
    cin >> t;

    while( t-- )
        {
            cin >> n;
            map<int, int>m;
            int sol = 0;

            for( int i = 1; i <= n; i++ )
                {
                    cin >> a[i];
                    int nr = 0;

                    while( a[i]%2==0 )
                        {
                            nr++;
                            a[i] /= 2;
                        }

                    m[a[i]] = max( m[a[i]], nr );
                }

            for( auto it : m )
                sol += it.nd;

            cout << sol << '\n';
        }

    return 0;
}
