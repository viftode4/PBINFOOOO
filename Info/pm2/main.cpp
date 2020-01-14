#include <bits/stdc++.h>
using namespace std;
ifstream fin( "pm2.in" );
ofstream fout( "pm2.out" );
vector<int>st;
vector<int>g[110], f[110];
int n, use[110], k;
int timp[110];
int v[110];
int t1[110], t2[110];
void dfs( int x )
{
    use[x] = 0;

    for( auto it : g[x] )
        if( !use[it] )
            dfs( it );

    st.push_back( x );
}
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        fin >> timp[i];

    for( int i = 1; i <= n; i++ )
        {
            fin >> k;

            while( k-- )
                {
                    int x;
                    fin >> x;
                    f[i].push_back( x );
                    g[x].push_back( i );
                }
        }

    for( int i = 1; i <= n; i++ )
        if( !use[i] )
            dfs( i );

    reverse( st.begin(), st.end() );

    for( auto b : st )
        {
            int mx = 0;

            for( auto j : f[b] )
                mx = max( mx, v[j] );

            t1[b] = mx;
            v[b] = mx + timp[b];
        }

    int sol = 0;

    for( int i = 1; i <= n; i++ )
        {
            sol = max( sol, v[i] );
            v[i] = 0;
        }

    fout << sol << '\n';
    reverse( st.begin(), st.end() );

    for( auto b : st )
        {
            int mx = 0;

            for( auto j : g[b] )
                mx = max( mx, v[j] );

            t2[b] = sol - mx - timp[b];
            v[b] = mx + timp[b];
        }

    for( int i = 1; i <= n; i++ )
        fout << t1[i] << ' ' << t2[i] << '\n';

    return 0;
}
