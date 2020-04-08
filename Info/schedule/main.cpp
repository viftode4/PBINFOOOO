#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "test.in" );
ofstream fout( "ceva.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
ll t, k;
ll n, m, ceva;
pair<ll, ll>a[100005];
ll d;
int ok( ll mid, ll d )
{

    ll s = 0;
    vector<int> sol;

    for( int i = 1; i <= n; i++ )
        sol.pb( ( mid - a[i].st ) / a[i].nd * 1LL );

    sort( sol.begin(), sol.end() );
    reverse( sol.begin(), sol.end() );

    for( int i = 0; i < k; i++ )
        s += sol[i];

    if( s >= d )
        return 1;

    return 0;
}
ll cauta( ll d )
{
    ll l = 0, r = a[1].st + a[1].nd * d + 1000;

    while( r - l > 1 )
        {
            ll mid = ( l + r ) / 2;

            if( ok( mid, d ) )
                r = mid;
            else
                l = mid;
        }

    return r;
}
int main()
{
    fast();
    fin >> t;
    ceva = t;

    while( t-- )
        {
            fin >> n >> k >> d;

            for( int i = 1; i <= n; i++ )
                fin >> a[i].st >> a[i].nd;

            ll timp = cauta( d );
            fout << "Case #" << ceva - t << ": " << timp << '\n';
        }

    return 0;
}
