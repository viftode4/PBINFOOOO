#include <bits/stdc++.h>
using namespace std;

ifstream fin ( "partitie.in" );
ofstream fout ( "partitie.out" );
int n, d, in, x;
struct nr
{
    int x, i, sol;
} a[1000004];
int cmpx ( nr&a, nr&b )
{
    return a.x < b.x;
}
int cmpi ( nr&a, nr&b )
{
    return a.i < b.i;
}
int main()
{
    fin >> n >> d;

    for ( int i = 1; i <= n; i++ )
        {
            fin >> x;
            a[i].x = x;
            a[i].i = i;
        }

    sort ( a + 1, a + n + 1, cmpx );
    int j = 1;

    for ( int i = 1; i <= n; i++ )
        {
            while ( j <= n && abs ( a[j].x - a[i].x ) < d )
                j++;

            in = max ( in, abs ( i - j ) );
        }

    fout << in << '\n';

    for ( int i = 1; i <= n; i++ )
        a[i].sol = i % in + 1;

    sort ( a + 1, a + n + 1, cmpi );

    for ( int i = 1; i <= n; i++ )
        fout << a[i].sol << ' ';

    return 0;
}
