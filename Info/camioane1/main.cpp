#include <bits/stdc++.h>
using namespace std;
ifstream fin( "camioane.in" );
ofstream fout( "camioane.out" );
unsigned long long n, m, nr;
struct camion
{
    unsigned long long i, v;
} b[100010], a[100010];
int sol[100010];
int cond( camion a, camion b )
{
    return a.v < b.v;
}
int main()
{
    fin >> n >> m;

    for( int i = 1; i <= n; i++ )
        {
            fin >> a[i].v;
            a[i].i = i;
        }

    sort( a + 1, a + n + 1, cond );

    for( int i = 1; i <= m; i++ )
        {
            fin >> b[i].v;
            b[i].i = i;
        }

    sort( b + 1, b + m + 1, cond );

    int x = n, y = m;

    while( x >= 1 && y >= 1 )
        {
            if( b[y].v > a[x].v )
                y--;
            else
                {
                    nr++;
                    sol[a[x].i] = b[y].i;
                    x--;
                    y--;
                }
        }

    fout << nr << endl;

    for( int i = 1; i <= n; i++ )
        fout << sol[i] << ' ';

    return 0;
}
