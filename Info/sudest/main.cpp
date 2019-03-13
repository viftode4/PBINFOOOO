#include <fstream>
using namespace std;
ifstream fin( "sudest.in" );
ofstream fout( "sudest.out" );
struct q
{
    int s, d, v;
} a[1005][1005];
int n, k, x;
int v[1005][1005], s[1005][1005];
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= n; j++ )
            fin >> v[i][j];

    fin >> k;
    a[1][1].s = 1;
    a[1][1].d = 1;
    a[1][1].v = v[1][1];
    int t = 1;
    int nr = 1;

    for( int i = 1; i <= k; i++ )
        {
            fin >> x;

            for( int j = 1; j <= t; j++ )
                {
                    a[i + 1][2 * j - 1].s = a[i][j].s + x;
                    a[i + 1][2 * j - 1].d = a[i][j].d;

                    if( a[i + 1][2 * j - 1].d <= n && a[i + 1][2 * j - 1].s <= n )
                        a[i + 1][2 * j - 1].v = a[i][j].v + v[a[i + 1][2 * j - 1].s][ a[i + 1][2 * j - 1].d];

                    a[i + 1][2 * j].s = a[i][j].s;
                    a[i + 1][2 * j].d = a[i][j].d + x;

                    if( a[i + 1][2 * j].s <= n && a[i + 1][2 * j].d <= n )
                        a[i + 1][2 * j].v = a[i][j].v + v[a[i + 1][2 * j].s][a[i + 1][2 * j].d];
                }

            t *= 2;
        }

    int smin = 0;

    for( int i = 1; i <= t; i++ )
        {

                    if( smin < a[k + 1][i].v )
                        {
                            smin = a[k + 1][i].v;
                        }
        }

    fout << smin;
    return 0;
}
