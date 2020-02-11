#include <bits/stdc++.h>
using namespace std;
ifstream fin( "p2sah.in" );
ofstream fout( "p2sah.out" );
#define MOD 100003
long long cer, n, k;
long long lgput( long long x, long long k )
{
    long long r = 1;

    while( k )
        {
            if( k % 2 )
                r = ( x * r ) % MOD;

            x = ( x * x ) % MOD;
            k /= 2;
        }

    return r % MOD;
}
int main()
{
    fin >> cer >> n >> k;

    if( cer == 1 )
        fout << lgput( 3, k - 1 ) % MOD;

    return 0;
}
