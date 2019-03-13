#include <bits/stdc++.h>
using namespace std;
ifstream fin( "intervale4.in" );
ofstream fout( "intervale4.out" );
struct q
{
    int s, d;
} a[100005], x;
int inters( q a, q b )
{
    if( a.s > b.d || b.s > a.d )
        return 0;

    return 1;
}
int n, v;
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        {
            fin >> x.s >> x.d;
            a[++v] = x;

            while( v >= 2 && inters( a[v], a[v - 1] ) )
                {
                    a[v - 1].s = min( a[v].s, a[v - 1].s );
                    a[v - 1].d = max( a[v].s, a[v - 1].d );
                    v--;
                }
        }

    fout << v << endl;
    return 0;
}
