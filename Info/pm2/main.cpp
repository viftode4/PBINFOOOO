#include <bits/stdc++.h>
using namespace std;
ifstream fin( "pm2.in" );
ofstream fout( "pm2.out" );
vector<int>st;
vector<int>g[110], f[110];
int n, use[110], k;
int timp[110];
int t1[110], t2[110];
int ttotal;
void dfs( int x )
{
    use[x] = 1;

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

    for( int i = 0; i < n; i++ )
        {
            int nod = st[i];

            for( auto it : g[nod] )
                t1[it] = max( t1[it], t1[nod] + timp[nod] );

            ttotal = max( ttotal, t1[nod] + timp[nod] );
        }

    reverse( st.begin(), st.end() );

    for( int i = 1; i <= n; i++ )
        t2[i] = ttotal - timp[i];

    for( int i = 0; i < n; i++ )
        {
            int nod = st[i];

            for( auto it : f[nod] )
                t2[it] = min(t2[it],t2[nod] - timp[it]);
        }

    fout << ttotal << '\n';

    for( int i = 1; i <= n; i++ )
        fout << t1[i] << ' ' << t2[i] << '\n';

    return 0;
}
