#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[1010];
int main()
{
    cin >> k;

    while( k-- )
        {
            cin >> n;
            int amax = 0;

            for( int i = 1; i <= n; i++ )
                cin >> a[i];

            sort( a + 1, a + n + 1, greater<int>() );
            int nr = 0;

            for( int x = 1000; x >= 1; x-- )
                {
                    nr = 0;

                    for( int i = 1; i <= n; i++ )
                        if( a[i] >= x )
                            nr++;
                        else
                            break;

                    if( nr >= x )
                        {
                            cout << x << '\n';
                            break;
                        }
                }
        }

    return 0;
}
