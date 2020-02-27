#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "xxx.in" );
ofstream fout( "xxx.in" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}

int main()
{
    fast();
    ll t;
    cin >> t;

    while( t-- )
        {
            ll n, x, y, maxi, mini;
            cin >> n >> x >> y;

            if( ( x == y && y == 1 ) || n == 1 )
                {
                    cout << 1 << ' ' << 1 << '\n';
                    continue;
                }

            if( x > y )
                swap( x, y );

            ll s;
            s = x + y;
            ll cat = s - n;

            cout << max( 1LL, cat + 1LL ) << ' ';
            cat = s - 1LL;
            cout << cat << '\n';
        }

    return 0;
}
