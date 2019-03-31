#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "agora.in" );
ofstream fout ( "agora.out" );
long long a[1011][1011];
int x, y, q;
int sx, sy, dx, dy;
void afisare()
{
    for ( int i = 0; i <= x; i++ )
        {
            for ( int j = 0; j <= y; j++ )
                fout << a[i][j] << ' ';

            fout << endl;
        }
}
int ok ( int i, int j )
{
    double d = sqrt ( i * i + j * j );

    if ( abs( d - ( int )d )  <= 0.01 && __gcd ( i, j ) == 1 )
        return 1;

    return 0;
}
int main()
{
    fin >> x >> y >> q;

    for ( int i = 1; i <= x; i++ )
        for ( int j = 1; j <= y; j++ )
            if ( ok ( i, j ) )
                a[i][j] = 1;

    for ( int i = 1; i <= x; i++ )
        for ( int j = 1; j <= y; j++ )
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];

    afisare();

    for ( int i = 1; i <= q; i++ )
        {
            fin >> sx >> sy >> dx >> dy;
            long long s = 0;

            sx = max( sx, 1 );
            sy = max( sy, 1 );
            dx = max( dx, 1 );
            dy = max( dy, 1 );

           // fout << a[dx][sy] << ' ' << a[dx][dy - 1] << ' ' << a[sx][sy - 1] << ' ' << a[sx - 1][dy - 1] << '\n';
            s = a[dx][sy] - a[dx][dy - 1] - a[sx][sy - 1] + a[sx - 1][dy - 1];
            fout << s << '\n';
        }

    //  afisare();

    return 0;
}
