#include <bits/stdc++.h>
using namespace std;
ifstream fin( "2sah.in" );
ofstream fout( "2sah.out" );
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
struct matrix
{
    int x[3][3] = {{1, 1, 0}, {1, 0, 1}, {1, 0, 0}};
} mat, rez;
matrix operator*( matrix a, matrix b )
{
    matrix rez;

    for( int i = 0; i < 3; i++ )
        for( int j = 0; j < 3; j++ )
            {
                rez.x[i][j] = 0;

                for( int k = 0; k < 3; k++ )
                    rez.x[i][j] = ( rez.x[i][j] + 1LL * a.x[i][k] * b.x[k][j] % MOD ) % MOD;
            }

    return rez;
}
void lgput_mat( matrix mat, int k )
{
    k--;

    while( k )
        {
            if( k % 2 )
                rez = rez * mat;

            mat = mat * mat;
            k /= 2;
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
            lgput_mat( mat, n-k-1 );
            fout << ( ( ( 1LL * rez.x[0][0] * 2 ) % MOD + 1LL * rez.x[1][0] ) % MOD + 1LL * rez.x[2][0] ) % MOD;
        }

    return 0;
}
