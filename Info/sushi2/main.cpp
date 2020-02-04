#include <bits/stdc++.h>
using namespace std;
ifstream fin( "sushi2.in" );
ofstream fout( "sushi2.out" );
#define pb push_back
#define mp make_pair
#define nd second
#define st first


//ciclu euler <3
int pas;
vector< pair<int, int> >pasi_euler;
map<int, map<int, int> >ord_euler;
vector<int>g[100005];
vector<int>t_nod[100005];
int use[100005];
//first - nod
//second - directia
int n, m, k;
int sol[100005];
void dfs_ord( int x )
{
    use[x] = 1;

    for( auto it : g[x] )
        if( !use[it] )
            {
                // intru in nod it
                pasi_euler.pb( mp( x, it ) );
                ord_euler[x][it] = pas++;
                t_nod[it].pb( pas - 1 );
                dfs_ord( it );
                // ma intorc din it in x
                pasi_euler.pb( mp( it, x ) );
                ord_euler[it][x] = pas++;
                t_nod[x].pb( pas - 1 );
            }
}
int main()
{
    fin >> n >> m;

    for( int i = 1; i <= n; i++ )
        {
            fin >> k;

            for( int j = 1; j <= k; j++ )
                {
                    int x;
                    fin >> x;
                    g[i].pb( x );
                }
        }

    dfs_ord( 1 );

    for( int i = 1; i <= m; i++ )
        {
            int x, y, t, p;
            fin >> x >> y >> t;
            p = ord_euler[x][y];

            for( int j = 1; j <= n; j++ )
                {
                    if( j == x )
                        continue;

                    if( j == y )
                        {
                            sol[j] = max( sol[j], 1 + t );
                            continue;
                        }

                    for( auto it : t_nod[j] )
                        {
                            if( it > p )
                                sol[j] = max( sol[j], it - p + t + 1 );
                            else
                                sol[j] = max( sol[j], 2 * n - p - 1 + it + t );
                        }
                }
        }

    for( int i = 1; i <= n; i++ )
        fout << sol[i] << ' ';

    return 0;
}
