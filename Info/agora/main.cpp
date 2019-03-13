#include <bits/stdc++.h>
using namespace std;
ifstream fin( "agora.in" );
ofstream fout( "agora.out" );
int x, y, q;
int sx, sy, dx, dy;
int a[7010][7010];
void afisare()
{
    for( int i = 0; i <= x; i++ )
        {
            for( int j = 0; j <= y; j++ )
                fout << a[i][j] << ' ';

            fout << endl;
        }
}
int main()
{
    fin >> x >> y;

    for( int i = 1; i <= x; i++ )
        for( int j = 1; j <= y; j++ )
            if( __gcd( i, j ) == 1 )
                a[i][j]++;
/*
    for( int i = 1; i <= x; i++ )
        for( int j = 1; j <= y; j++ )
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];*/
    afisare();
    return 0;
}
