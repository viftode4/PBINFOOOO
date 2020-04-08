#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
#define MOD 998244353
using namespace std;
ifstream fin( "xxx.in" );
ofstream fout( "xxx.in" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
ll sol = 1, sum;
ll n, k, p;
ll a[200005];
int main()
{
    fast();
    cin >> n >> k;
    ll l = n - k;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a[i];
            p++;

            if( a[i] > l )
                {
                    sum += a[i];


                    if( sum != a[i] )
                        sol = ( sol * p ) % MOD;

                    p = 0;
                }
        }

    cout << sum << ' ' << sol;
    return 0;
}
