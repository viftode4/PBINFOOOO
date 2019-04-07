#include <bits/stdc++.h>
using namespace std;
ifstream fin( "matrice.in" );
ofstream fout( "matrice.out" );
int a[30005][30005];
int r[30005], c[30005];
int main()
{
    fin >> n >> m >> a;

    for( int i = 1; i <= n; i++ )
        fin >> r[i];

    for( int j = 1; j <= m; j++ )
        fin >> c[i];

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            a[i][j] = a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1] + ( c[i] ^ b[j] );

    return 0;
}
