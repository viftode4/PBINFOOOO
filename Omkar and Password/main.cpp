#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin ( "xxx.in" );
ofstream fout ( "xxx.in" );
void fast()
{
    cin.tie ( 0 );
    ios_base::sync_with_stdio ( 0 );
}
ll t, n, k, a[200005];
int main()
{
    fast();
    cin >> t;

    while ( t-- )
        {
            cin >> n >> k;

            for ( int i = 1; i <= n; i++ )
                cin >> a[i];

            if ( k > 1 )
                k = 2 + k % 2;

            while ( k-- )
                {
                    ll mx = -1000000000;

                    for ( int i = 1; i <= n; i++ )
                        {
                            mx = max ( mx, a[i] );
                        }

                    for ( int i = 1; i <= n; i++ )
                        {
                            a[i] = mx - a[i];
                        }
                }

            for ( int i = 1; i <= n; i++ )
                cout << a[i] << ' ';

            cout << '\n';
        }

    return 0;
}
