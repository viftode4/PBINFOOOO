#include <bits/stdc++.h>
#define ll long long
#define eps 1e-8
using namespace std;
ifstream fin( "rufe.in" );
ofstream fout( "rufe.out" );
ll n, m, a, b, k, rest;
int ok( ll x )
{
    ll nr = 2 * x * ( x + 1 ) * 1LL;
    ll lsus = 0, ljos = 0;
    ll lst = 0, ldr = 0;

    //iese jos
    if( a - x < 1 )
        {
            ll z = abs( a - x ) * 1LL + 1 * 1LL;
            ljos = z * ( z - 1 ) * 1LL + z * 1LL;
        }

    //iese sus
    if( a + x > n )
        {
            ll z = a + x - n * 1LL;
            lsus = z * ( z - 1 ) * 1LL + z * 1LL;
        }

    //iese st
    if( b - x < 1 )
        {
            ll z = abs( b - x ) * 1LL + 1;
            lst = z * ( z - 1 ) * 1LL + z;
        }

    //iese dr
    if( b + x > m )
        {
            ll z = b + x * 1LL - m * 1LL;
            ldr = z * ( z - 1 ) * 1LL + z;
        }

//coltul dreapta sus pinex (comun)
    if( lsus && ldr )
        {
            ll d = abs( m + 1 - b ) * 1LL + abs( 0 - a ) * 1LL;
            ll z = x - d + 1;

            if( z > 0 )
                nr -= z * ( z + 1 ) * 1LL / 2 * 1LL;
        }

    //coltul stanga sus pinex (comun)
    if( lsus && lst )
        {
            ll d = a + b;
            ll z = x - d + 1;

            if( z > 0 )
                nr -= z * ( z + 1 ) * 1LL / 2 * 1LL;
        }

//coltul stanga jos pinex (comun)
    if( ljos && lst )
        {
            ll d = abs( n + 1 - a ) * 1LL + abs( 0 - b ) * 1LL;
            ll z = x - d + 1;

            if( z > 0 )
                nr -= z * ( z + 1 ) / 2 * 1LL;
        }

//coltul dreapta jos pinex (comun)
    if( ljos && ldr )
        {
            ll d = abs( n + 1 - a * 1LL ) * 1LL + abs( m + 1 - b ) * 1LL;
            ll z = x - d + 1;

            if( z > 0 )
                nr -= z * ( z + 1 ) / 2 * 1LL;
        }

    if( nr <= rest )
        return 1;

    return 0;
}
int main()
{
    fin >> n >> m >> a >> b >> k;
    ll l = 0;
    ll r = n + m;
    rest = 1LL * n * m - k * 1LL;

    while( r - l > 1LL )
        {
            ll mid = 1LL * ( l + r ) / 2 * 1LL;

            if( ok( mid ) )
                l = mid * 1LL;
            else
                r = mid * 1LL;
        }

    fout << l * 1LL + 1 * 1LL;
    return 0;
}
