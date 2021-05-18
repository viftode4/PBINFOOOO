#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ( "serbare2.in" );
ofstream fout ( "serbare2.out" );
int n, k, i, j, x;
int a[101][101];
int cat[101];
int v[11];
void gen ( int n, int t, int k, int w )
{
    if ( k > t )
        {
            int ok = 1;

            for ( int i = 1; i <= t; i++ )
                for ( int j = 1; j <= t; j++ )
                    if ( a[v[i]][v[j]] != 1 && i != j )
                        ok = 0;

            if ( ok )
                {
                    fout << t;
                    exit ( 0 );
                }
        }
    else
        {
            for ( int i = w; i <= n; i++ )
                {
                    if ( cat[i] < t )
                        continue;

                    int ok = 1;

                    for ( int j = 1; j < k; j++ )
                        if ( a[v[j]][i] != 1 || a[i][v[j]] != 1 )
                            {
                                ok = 0;
                                break;
                            }

                    if ( !ok )
                        continue;

                    v[k] = i;
                    gen ( n, t, k + 1, i + 1 );
                }
        }
}
int main()
{
    fin >> n >> k;

    for ( int i = 1; i <= n; i++ )
        {
            cat[i] = 1;

            for ( int j = 1; j <= n; j++ )
                {
                    fin >> a[i][j];
                    cat[i] += a[i][j];
                }
        }

    for ( int t = k; t >= 1; t-- )
        gen ( 100, t, 1, 1 );

    return 0;
}
