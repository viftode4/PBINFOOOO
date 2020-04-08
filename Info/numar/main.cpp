#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "numar.in" );
ofstream fout( "numar.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
ll n, m, lim;
ll a[110];
vector<ll>coef;
void gen( int p, ll prod, int last )
{
    for( int i = last + 1; i <= n; i++ )
        {
            if( prod * a[i] > lim )
                return;

            if( p % 2 == 1 )
                coef.pb( prod * a[i] );
            else
                coef.pb( -prod * a[i] );

            gen( p + 1, prod * a[i], i );
        }
}
ll pinex( ll x )
{
    ll val = 0;

    for( auto it : coef )
        if( it != 0 )
            val += x / it;

    return val;
}
int main()
{
    fast();
    fin >> n >> m;

    for( int i = 1; i <= n; i++ )
        fin >> a[i];

    lim = m * a[1];

    gen( 1, 1, 0 );
    ll l = 0, r = lim + 2, sol = 0;

    while( r - l > 1 )
        {
            ll mid = ( l + r ) / 2;
            ll val = pinex( mid );

            if( val == m )
                {
                    sol = mid;
                    break;
                }
            else if( val < m )
                l = mid;
            else
                r = mid;
        }

    for( ll i = sol; i >= 0; i-- )
        for( int j = 1; j <= n; j++ )
            if( i % a[j] == 0 )
                {
                    fout << i;
                    return 0;
                }

    return 0;
}
