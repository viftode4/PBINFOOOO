#include <bits/stdc++.h>
using namespace std;
ifstream fin( "p2sah.in" );
ofstream fout( "p2sah.out" );
#define MOD 100003
long long cer, n, k;
long long baza[3][3] = {{1, 1, 0}, {1, 0, 1}, {1, 0, 0}};
long long rez[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
void afisare( long long rez[3][3] )
{
    fout << "MAT:\n";

    for( int i = 0; i < 3; i++ )
        {
            for( int j = 0; j < 3; j++ )
                fout << rez[i][j] << ' ';

            fout << endl;
        }
}
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
void inmulteste( long long a[3][3], long long b[3][3], long long c[3][3] )
{
    long long aux[3][3];

    for( int x = 0; x < 3; x++ )
        for( int y = 0; y < 3; y++ )
            {
                aux[x][y] = 0;

                for( int i = 0; i < 3; i++ )
                    aux[x][y] = ( aux[x][y] + ( a[x][i] * b[i][y] ) % MOD ) % MOD;;
            }

    for( int i = 0; i < 3; i++ )
        for( int j = 0; j < 3; j++ )
            c[i][j] = aux[i][j] ;
}
void lgput_mat( long long baza[3][3], long long k )
{
    while( k )
        {
            if( k % 2 )
                {
                    inmulteste( rez, baza, rez );
                    //afisare( rez );
                }

            inmulteste( baza, baza, baza );
            k = k / 2;
        }
}

int main()
{
    fin >> cer >> n >> k;

    if( cer == 1 )
        {
            fout << lgput( 3, k - 1 ) % MOD;
            return 0;
        }


    if( k == n )
        fout << 1;
    else if( k == n - 1 )
        fout << 2;
    else
        {
            lgput_mat( baza, k - 1 );
            fout << ( rez[0][0] * 2 + rez[0][1] + rez[0][2] ) % MOD;
        }

    return 0;
}
