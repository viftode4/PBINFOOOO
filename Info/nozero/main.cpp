#include <bits/stdc++.h>
using namespace std;
ifstream fin( "nozero.in" );
ofstream fout( "nozero.out" );
int n, k, cate;
int use[15];
long long p[15], sol, pas;
long long fact[16];
int contine0( long long x )
{
    while( x )
        {
            if( x % 10 == 0 )
                return 1;

            x /= 10;
        }

    return 0;
}
int main()
{
    fin >> n >> k;
    fact[0] = 1;
    k--;

    for( int i = 1; i <= 15; i++ )
        fact[i] = fact[i - 1] * i;

    while( fact[cate] <= k )
        cate++;

    long long sum = 0;

    for( int i = 1; i <= cate; i++ )
        {
            p[i] = 1;

            while( sum + fact[cate - i] <= k )
                {
                    p[i]++;
                    sum += fact[cate - i];
                }
        }

    for( int i = cate - 1; i >= 1; i-- )
        for( int j = i + 1; j <= cate; j++ )
            if( p[i] <= p[j] )
                p[j]++;

    long long c = 1, bun = 1, sumbun = 0, ant, cn;
    long long rest = n - cate;
    sumbun = ant = rest % 10;
    cn = rest / 10;

    while( c <= rest )
        {
            if( bun != 1 )
                sumbun += bun;

            bun = bun * 9;


            if( cn % 10 != 0 )
                {
                    sumbun += ( cn % 10 - 1 ) * bun;
                    //fout << ( cn % 10 - 1 ) * bun << ' ' << sumbun << '\n';
                    ant += ( cn % 10 - 1 ) * bun;
                }
            else if( cn != 0 )
                sumbun -= ant, ant = 0;

            cn /= 10;
            c *= 10;

        }

    for( int i = 1; i <= cate; i++ )
        {
            if( contine0( i + rest ) || contine0( p[i] + rest )  )
                continue;

            sumbun++;
        }

    fout << sumbun;
    return 0;
}
