#include <bits/stdc++.h>
using namespace std;
ifstream fin( "nmult.in" );
ofstream fout( "nmult.out" );
const int MOD = 666013;
long long n, k, w;
long long fact[100001];
int fpw( long long baza, long long put )
{
    long long r = 1;

    while( put > 0 )
        {
            if( put % 2 == 1 )
                r = ( r * baza ) % MOD;

            baza = ( baza * baza ) % MOD;
            put /= 2;
        }

    return r % MOD;
}
long long imod( const long long nr )
{
    return fpw( nr, MOD - 2 );
}
long long comb( const long long n, const long long k )
{
    return( ( fact[n] * imod( fact[n - k] ) ) % MOD * imod( fact[k] ) ) % MOD;
}
int main()
{
    fin >> n >> k >> w;
    fact[0] = 1;

    for( int i = 1; i <= 100000; i++ )
        fact[i] = ( i * fact[i - 1] ) % MOD;

    long long t = n -  ( k - 1 ) * w;
    //fout << t << ' ';
    fout << comb( k, t );
    return 0;
}
