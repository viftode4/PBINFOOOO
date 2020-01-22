#include <bits/stdc++.h>
using namespace std;
ifstream fin( "ornament.in" );
ofstream fout( "ornament.out" );
#define st first
#define nd second
int n, cer, m, nr;
int use[20];
struct cub
{
    int f[5];
    //1 N
    //2 E
    //3 S
    //4 W
} a[20];
//ordinea in care iau elementele matricii
//primele 4 latura 2
//primele 9 latura 3
//primele 16 latura 4
//pt complexitate asa scap de parcurgere
//elementele sunt luate tip lee si asa verific doar
//stanga si sus la fiecare ornament sa vad daca e bun si compar cu ornamentele de acolo
vector< pair<int, int> >o{{0, 0}, {1, 1}, {1, 2}, {2, 1}, {2, 2}, {1, 3}, {3, 1}, {2, 3}, {3, 2}, {3, 3}, {1, 4}, {4, 1}, {2, 4}, {4, 2}, {3, 4}, {4, 3}, {4, 4}};
int sol[20][20];
int verif( cub b, int i, int j )
{
    cub s = a[sol[i - 1][j]], d = a[sol[i][j - 1]];

    //S cu N
    //E cu W
    //daca e latura de cul 5 e bun
    if(  ( s.f[3] == b.f[1] || s.f[3] == 5 ) && ( d.f[2] == b.f[4] || d.f[2] == 5 )  )
        return 1;

    return 0;
}
void gen( int p )
{
    if( p > m * m )
        {
            nr++;

            if( cer == 1 )
                {
                    for( int i = 1; i <= m; i++ )
                        {
                            for( int j = 1; j <= m; j++ )
                                fout << sol[i][j] << ' ';

                            fout << '\n';
                        }

                    exit( 0 );
                }

            return;
        }

    int x = o[p].st;
    int y = o[p].nd;

    for( int i = 1; i <= n; i++ )
        if( verif( a[i], x, y ) && !use[i] )
            {
                sol[x][y] = i;
                use[i] = 1;
                gen( p + 1 );
                use[i] = 0;
            }

}
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        fin >> a[i].f[1] >> a[i].f[2] >> a[i].f[3] >> a[i].f[4];

    //matricea solutie contine numai 0
    //fac cubul 0 sa aiba toate fetele de culoare 5
    //peste 5 se poate pune orice culoare ceva de genu
    //pt lene sa nu scriu in plus
    //in verificare daca e bun asezat un ornament
    a[0].f[1] = a[0].f[2] = a[0].f[3] = a[0].f[4] = 5;
    fin >> cer;

    if( n == 4 )
        m = 2;
    else if( n == 9 )
        m = 3;
    else if( n == 16 )
        m = 4;

    gen( 1 );
    fout << nr;
    return 0;
}
