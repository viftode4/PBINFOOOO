#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "rascoala.in" );
ofstream fout ( "rascala.out" );
int cer, z;
int n, m, k, nr = 1;
int si = INT_MAX, sj = INT_MAX, di, dj;
int a[505][505];
int l[505];
int d[505];
struct pct
{
    int i, j, ord;
};
int cond ( const pct a, const pct b )
{
    if ( b.ord == a.ord )
        {
            if ( b.i < a.i )
                return 1;
            else if ( b.i == a.i && b.j < a.j )
                return 1;

            return 0;
        }

    if ( a.ord != 0 && b.ord != 0 && a.ord > b.ord )
        return 1;

    return 0;
}
vector<pct> v[1000010];
int vmin = INT_MAX;
int main()
{
    fin >> cer;
    fin >> n >> m >> k;

    for ( int i = 1; i <= n; i++ )
        l[i] = INT_MAX;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            {
                fin >> z;
                vmin = min ( vmin, z );
                pct x;
                x.i = i;
                x.j = j;
                x.ord = 0;
                v[z] .push_back ( x );
            }

    int i = vmin - 1;

    while ( k )
        {
            if ( v[i].empty() || i == -1 )
                {
                    i++;
                    sort ( v[i].begin(), v[i].end(), cond );
                    /*fout << "VALOARE " << i << '\n';

                    for ( auto it : v[i] )
                        fout << it.i << ' ' << it.j << ' ' << it.ord << '\n';

                    fout << endl;*/
                }

            pct x = v[i].back();
            v[i].pop_back();
            a[x.i][x.j] = 1;
            l[x.i] = min ( l[x.i], x.j );
            d[x.i] = max ( x.j, d[x.i] );

            if ( x.ord == 0 )
                {
                    x.ord = nr;
                    nr++;
                }

            v[i + 1].push_back ( x );
            k--;
        }

    if ( cer == 1 )
        {
            int s = 0;

            for ( int i = 1; i <= n; i++ )
                for ( int j = 1; j <= m; j++ )
                    s += a[i][j];

            fout << s << '\n';

            while ( v[i].empty() )
                i++;

            fout << i << '\n';
            return 0;
        }

    int dmax = 0, dr = 0;

    for ( int i = 1; i <= n; i++ )
        {
            if ( l[i] > m )
                continue;

            for ( int j = i; j <= n; j++ )
                {
                    if ( d[j] < 1 )
                        continue;

                    dr = j - i + d[j] - l[i];
                    dmax = max ( dr, dmax );
                }
        }

    fout << dmax;
    return 0;
}
