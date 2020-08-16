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
int n;
int a[1000][1000];
ll lgput ( ll baza, ll exp )
{
    ll r = 1;

    while ( exp )
        {
            if ( exp % 2 == 1 )
                r = r * baza;

            baza = baza * baza;
            exp /= 2;
        }

    return r;
}
int main()
{
    fast();
    cin >> n;

    while ( n-- )
        {
            ll x;
            cin >> x;
            x--;
            ll nr = 0;

            for ( ll i = 1; i <= x; i *= 2 )
                if ( i & x )
                    nr++;

            cout << lgput ( 2, nr ) << '\n';
        }

    return 0;
}
