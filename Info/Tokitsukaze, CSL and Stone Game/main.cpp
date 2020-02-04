#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define NMAX 100006
#define INF 2000000000
using namespace std;
typedef long long ll;
ll n, i, v[NMAX], j, pasi, nr, peg, x;
int main()
{
    ios_base::sync_with_stdio( false );
    cin.tie();
    cin >> n;

    for( i = 1; i <= n; i++ )
        cin >> v[i];

    sort( v + 1, v + n + 1 );

    for( i = 2; i <= n; i++ )
        {
            if( v[i] == v[i - 1] )
                nr++, peg = i - 1;
        }

    if( nr > 1 || ( v[1] == v[2] && v[1] == 0 ) )
        {
            cout << "cslnb";
            return 0;
        }

    if( nr == 1 && ( peg > 1 && v[peg - 1] + 1 == v[peg] ) )
        {
            cout << "cslnb";
            return 0;
        }

    pasi += v[1];
    v[1] = 0;
    i = 1;

    while( v[i] == 0 && i <= n )
        i++;

    x = 1;

    for( i; i <= n; i++ )
        {
            pasi += v[i] - x;
            x++;
        }

//    cout<<pasi;
    if( pasi % 2 )
        cout << "sjfnb";
    else
        cout << "cslnb";

    return 0;
}
