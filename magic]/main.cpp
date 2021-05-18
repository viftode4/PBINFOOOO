#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin ( "magic.in" );
ofstream fout ( "magic.out" );
void fast()
{
    cin.tie ( 0 );
    ios_base::sync_with_stdio ( 0 );
}
ll n, l;
ll x[202], e[202];
ll sol[202];
int main()
{
    fast();
    cin >> n >> l;

    for ( int i = 1; i <= n; i++ )
        cin >> x[i];

    for ( int i = 1; i <= n; i++ )
        {
            cin >> e[i];
            sol[x[i]] = e[i];
        }

    for ( ll i = 1; i < l; i++ )
        {
            if ( sol[i] )
                continue;

            for ( int t = 1; t <= 9 && i - t >= 0; t++ )
                if ( t % sol[i - t] == 0 || sol[i - t] % t == 0 )
                    sol[i] = t;
        }

    for ( ll i = 0; i < l; i++ )
        cout << sol[i] << ' ';

    return 0;
}
