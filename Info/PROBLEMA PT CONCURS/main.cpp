#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "comp.in" );
ofstream fout ( "comp.out" );
int a[1001][1001], n, m,  ok, dim, cer;
int b[1001][1001], v[5], fr[1001];
int di[] = {0, 1, 0, -1, 0};
int dj[] = {0, 0, 1, 0, -1};
int main()
{
    fin >> cer >> n >> m;
    if ( cer == 2 )
    {
        fin >> ok;
        for ( int i = 1; i <= n; i++ )
            for ( int j = 1; j <= m; j++ )
            {
                fin >> a[i][j];
                b[i][j] = a[i][j];
            }
        for ( int i = 0; i <= n + 1; i++ )
            a[i][0] = a[i][m + 1] = -1;
        for ( int i = 0; i <= m + 1; i++ )
            a[0][i] = a[n + 1][i] = -1;
        while ( ok > 0 )
        {
            ok--;
            for ( int i = 1; i <= n; i++ )
                for ( int j = 1; j <= m; j++ )
                {
                    int nr, el, nrmax = 0;
                    for ( int d = 1; d <= 4; d++ )
                        v[d] = a[i + di[d]][j + dj[d]];
                    for ( int d = 1; d < 4; d++ )
                    {
                        nr = 1;
                        if ( v[d] != -1 )
                            for ( int f = d + 1; f <= 4; f++ )
                                if ( v[d] == v[f] && v[f] != -1 )
                                    nr++;
                        if ( nrmax < nr )
                        {
                            nrmax = nr;
                            el = v[d];
                        }
                        else if ( nrmax == nr )
                        {
                            el = -1;
                        }
                    }
                    if ( el >= 0 )
                        b[i][j] = el;
                }
            for ( int i = 1; i <= n; i++ )
                for ( int j = 1; j <= m; j++ )
                    a[i][j] = b[i][j];
        }
        for ( int i = 1; i <= n; i++ )
            for ( int j = 1; j <= m; j++ )
                fr[a[i][j]]++;
        for ( int i = 1; i <= 1000; i++ )
            if ( fr[i] > 0 )
                dim++;
        fout << dim;
        for ( int i = 1; i <= n; i++ )
        {
            for ( int j = 1; j <= m; j++ )
                fout << a[i][j] << ' ';
            fout << endl;
        }
        return 0;
    }
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            fin >> a[i][j];

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            fr[a[i][j]]++;
    for ( int i = 1; i <= 1000; i++ )
        if ( fr[i] > 0 )
            dim++;
    fout << dim;
    return 0;
}
