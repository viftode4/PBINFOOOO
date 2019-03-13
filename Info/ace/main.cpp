#include <fstream>
using namespace std;
ifstream fin ( "ace.in" );
ofstream fout ( "ace.out" );
int a[1001][1001], n, m, cerinta, c[1001][1001];
int interior ( int i, int j )
{
    if ( i <= 0 || j <= 0 || i >= n + 1 || j >= m + 1 )
        return 0;
    return 1;
}
int viz ( int n, int m, int i, int j, int d )
{
    /* if ( !interior ( n + i, m + j ) )
         return 0;

     else
     {
         double b, c;
         b = a[n][m] / ( d - 1.0 );
         c = a[n + i][m + j] / d * 1.0;
         if ( b < c )
             return 1 + viz ( n + i, m + j, i, j, d + 1 );
     }*/
    int nr = 1;
    double b = 0, c = 0;
    while ( interior ( n + i, m + j ) )
    {
        b = ( double ) a[n][m] / ( d - 1 );
        c = ( double ) a[n + i][m + j] / d;
        if ( b < c )
            nr++;
        n = n + i;
        m = m + j;
        d++;
    }
    return nr;
}
int main()
{
    fin >> cerinta;
    fin >> n >> m;
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            fin >> a[i][j];
    if ( cerinta == 1 )
    {
        fout << viz ( n - 1, m, -1, 0, 2 ) + viz ( n, m - 1, 0, -1, 2 );
    }
    else
        return 0;
}
