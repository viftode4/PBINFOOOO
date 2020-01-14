#include <bits/stdc++.h>
using namespace std;
int n, q;
long long fr[15], x;
int main()
{
    cin >> q;

    while( q )
        {
            q--;

            for( int i = 0; i <= 13; i++ )
                fr[i] = 0;

            cin >> n;

            for( int i = 1; i <= n; i++ )
                {
                    cin >> x;
                    int nr = 0;

                    if( x > 2048 )
                        continue;

                    while( x )
                        {
                            x /= 2;
                            nr++;
                        }

                    fr[nr]++;
                }

            for( int i = 1; i <= 11; i++ )
                {
                    fr[i + 1] += fr[i] / 2;
                }

            if( fr[12] )
                cout << "YES\n";
            else
                cout << "NO\n";
        }

    return 0;
}
