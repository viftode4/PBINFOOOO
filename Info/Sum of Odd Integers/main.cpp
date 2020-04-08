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
            ll n, k;
            cin >> n >> k;
            ll kk = 2LL * k - 1LL;
            ll s = ( kk + 1LL ) * k / 2LL;
            ll diff = n - s;

            if( diff < 0 )
                {
                    cout << "NO\n";
                    continue;
                }

            if( diff % 2 == 1 )
                {
                    cout << "NO\n";
                    continue;
                }

            cout << "YES\n";
        }

    return 0;
}
