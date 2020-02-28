#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
FILE *fin = fopen( "ciclueuler.in", "r" );
FILE *fout = fopen( "ciclueuler.out", "w" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
vector<int>g[100005];
int use[500005];
int used[100005];
int n, m;
int x, y;
vector<int>euler;
void m_erase( int a, int b )
{
    int nr = 0;
    g[a].pop_back();

    for( auto it : g[b] )
        {
            nr++;

            if( it == a )
                {
                    g[b].erase( g[b].begin() + nr - 1 );
                    return;
                }

        }
}
void c_euler()
{
    stack<int>s;
    s.push( 1 );

    while( !s.empty() )
        {
            int x = s.top();

            if( g[x].empty() )
                {
                    s.pop();
                    euler.pb( x );
                    continue;
                }

            s.push( g[x].back() );
            m_erase( x, g[x].back() );
        }
}
void dfs( int x )
{
    used[x] = 1;

    for( auto it : g[x] )
        if( !used[it] )
            dfs( it );
}
void valid()
{
    dfs( 1 );

    for( int i = 1; i <= n; i++ )
        if( !used[i] || ( g[i].size() % 2 ) == 1 )
            {
                fprintf( fout, "-1" );
                exit( 0 );
            }
}
int main()
{

    fscanf( fin, "%d%d", &n, &m );

    for( int i = 1; i <= m; i++ )
        {
            fscanf( fin, "%d%d", &x, &y );
            g[x].pb( y );
            g[y].pb( x );
        }

    valid();

    c_euler();
    euler.pop_back();

    for( auto it : euler )
        fprintf( fout, "%d ", it );

    return 0;
}
