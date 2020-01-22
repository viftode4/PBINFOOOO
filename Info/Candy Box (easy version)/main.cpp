#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n, nr;
int t, x;
int fr[200005];
int main()
{
    cin >> t;

    while( t-- )
        {
            cin >> n;

            for( int i = 1; i <= n; i++ )
                    fr[i] = 0;
            for( int i = 1; i <= n; i++ )
                {
                    cin >> x;
                    fr[x]++;
                }

            sort( fr + 1, fr + n + 1 );
            reverse( fr + 1, fr + n + 1 );
            int ul = fr[1];
            nr = fr[1];

            for( int i = 2; i <= n + 1; i++ )
                {
                    if( ul == 0 )
                        break;

                    if( fr[i] >= ul )
                        {
                            ul--;
                            nr += ul;
                        }
                    else
                        {
                            nr += fr[i];
                            ul = fr[i];
                        }
                }

            cout << nr << '\n';
        }

    return 0;
}
