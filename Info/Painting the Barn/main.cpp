#include <bits/stdc++.h>
using namespace std;
ifstream fin( "paintbarn.in" );
ofstream fout( "paintbarn.out" );
int n, k;
int a[210][210];
int si=9999, sj=99999, di, dj;
struct qvadrat
{
    int x1, y1, x2, y2;
} p[110000];
int inter( int i, int j, int n );
int cul( int i, int j );
void afisare();
int main()
{
    fin >> n >> k;

    for( int i = 1; i <= n; i++ )
        {
            fin >> p[i].x1 >> p[i].y1 >> p[i].x2 >> p[i].y2;
            si = min( si, p[i].x1 );
            sj = min( sj, p[i].y1 );
            di = max( di, p[i].x2 );
            dj = max( dj, p[i].y2 );
        }

    for( int i = si; i <= di; i++ )
        for( int j = sj; j <= dj; j++ )
            a[i][j] = cul( i, j );

afisare();

    return 0;
}
int cul( int i, int j )
{
    int nr = 0;

    for( int k = 1; k <= n; k++ )
        if( inter( i, j, k ) )
            nr++;

    return nr;
}
int inter( int i, int j, int n )
{
    if( i < p[n].x1 || i > p[n].x2 || j < p[n].y1 || j > p[n].y2 )
        return 0;

    return 1;
}
void afisare()
{
    for( int i = si; i <= di; i++ )
        {
            for( int j = sj; j <= dj; j++ )
                fout << a[i][j] << ' ';

            fout << endl;
        }
}
