#include <bits/stdc++.h>
using namespace std;
ifstream fin( "castel1.in" );
ofstream fout( "castel1.out" );
int cer;
struct camera
{
    int i, j, aria;
    int x, y;
} c[10001];
bool cond( const camera a, const camera b )
{
    if( a.aria < b.aria )
        return 1;
    else if( a.aria == b.aria )
        {
            if( a.i > b.i )
                return 1;
            else if( a.i == b.i && a.j > b.j )
                return 1;
        }

    return 0;
}
int di[] = {0, 1, 0, -1};
int dj[] = {-1, 0, 1, 0};
int x[4] = {1, 2, 4, 8};
//          V, S, E, N
int n, a[110][110], m[110][110];
int p[110][110][4];
int nr = 1;
int inter( const int i, const int j );
void lee( const int i, const int j );
void afisare();
int main()
{
    fin >> cer;
    fin >> n;
    nr = 1;

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= n; j++ )
            {
                fin >> a[i][j];

                if( a[i][j] == 0 )
                    continue;

                for( int k = 0; k < 4; k++ )
                    if( ( x[k]&a[i][j] ) == x[k] )
                        {
                            p[i][j][k] = 1;

                            if( k == 0 )
                                p[i][j - 1][2] = 1;
                            else if( k == 1 )
                                p[i + 1][j][3] = 1;
                            else if( k == 2 )
                                p[i][j + 1][0] = 1;
                            else if( k == 3 )
                                p[i - 1][j][1] = 1;
                        }
            }

    m[0][0] = 1;
    lee( 0, 0 );

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= n; j++ )
            if( !m[i][j] )
                {
                    nr++;
                    lee( i, j );
                }

    if( cer == 1 )
        {
            fout << nr - 1 << '\n';
            return 0;
        }

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= n; j++ )
            {
                if( c[m[i][j]].i == 0 )
                    {
                        c[m[i][j]].i = i;
                        c[m[i][j]].j = j;
                    }

                c[m[i][j]].x = max( i, c[m[i][j]].x );
                c[m[i][j]].y = max( j, c[m[i][j]].y );
                c[m[i][j]].aria++;
            }

    sort( c + 2, c + nr + 1, cond );

    if( cer == 2 )
        {
            fout << c[nr].aria << '\n';
            return 0;
        }

    fout << c[nr].i << ' ' << c[nr].j << ' ' << c[nr].x << ' ' << c[nr].y << '\n';
    return 0;
}
void afisare()
{
    for ( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= n; j++ )
                fout << m[i][j] << ' ';

            fout << endl;
        }
}
int inter( const int i, const int j )
{
    if( i > n + 1 || i < 0 || j > n + 1 || j < 0 )
        return 0;

    return 1;
}
void lee( const int i, const int j )
{
    m[i][j] = nr;

    for( int d = 0; d < 4; d++ )
        if( inter( i + di[d], j + dj[d] ) && !p[i][j][d] && !m[i + di[d]][j + dj[d]] )
            lee( i + di[d], j + dj[d] );
}
