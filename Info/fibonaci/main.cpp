#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
#define MOD 666013
using namespace std;
ifstream fin( "kfib.in" );
ofstream fout( "kfib.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
struct matrix
{
    int x[2][2] = {{1, 1}, {1, 0}};
} mat, rez;
matrix operator*( matrix a, matrix b )
{
    matrix rez;

    for( int i = 0; i < 2; i++ )
        for( int j = 0; j < 2; j++ )
            {
                rez.x[i][j] = 0;

                for( int k = 0; k < 2; k++ )
                    rez.x[i][j] = ( rez.x[i][j] + 1LL * a.x[i][k] * b.x[k][j] % MOD ) % MOD;
            }

    return rez;
}
int n;
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
    fast();
    fin >> n;
    lgput_mat( mat, n - 1 );
    fout << rez.x[0][0];
    return 0;
}
