#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define nd second
#define st first
ifstream fin( "biperm.in" );
ofstream fout( "biperm.out" );
int n, nrc, nrm;
int a[10005];
int b[10005];
int use[10005];
vector<int>g[10005];
vector<int>f[10005];
void dfs( int i )
{
    use[i] = 1;

    for( auto it : g[i] )
        if( !use[it] )
            dfs( it );

}
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        fin >> a[i];

    for( int i = 1; i <= n; i++ )
        fin >> b[i];

    for( int i = 1; i <= n; i++ )
        {

            if( !g[a[i]].empty() || !f[b[i]].empty() )
                {
                    swap( a[i], b[i] );
                    nrm++;
                }

            g[a[i]].pb( b[i] );
            f[b[i]].pb( a[i] );
        }

    for( int i = 1; i <= n; i++ )
        if( !use[i] )
            {
                dfs( i );
                nrc++;
            }

    fout << ( long long )( 1 << nrc ) << ' ' << nrm << '\n';

    for( int i = 1; i <= n; i++ )
        fout << a[i] << ' ';

    fout << '\n';

    for( int i = 1; i <= n; i++ )
        fout << b[i] << ' ';

    return 0;
}
