#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "timeline.in" );
ofstream fout( "timeline.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
vector<pair<int, int>>g[100005];
int val[100005];
int grad[100005];
int n, m, c;
queue<int>q;
vector<int>st;
int main()
{
    fast();
    fin >> n >> m >> c;

    for( int i = 1; i <= n; i++ )
        fin >> val[i];

    for( int i = 1; i <= c; i++ )
        {
            int a, b, c;
            fin >> a >> b >> c;
            g[a].pb( {b, c} );
            grad[b]++;
        }

    for( int i = 1; i <= n; i++ )
        if( !grad[i] )
            q.push( i );

    while( !q.empty() )
        {
            int x = q.front();
            q.pop();
            st.pb( x );

            for( auto it : g[x] )
                {
                    grad[it.st]--;

                    if( grad[it.st] == 0 )
                        q.push( it.st );
                }
        }

    for( auto i : st )
        {
            for( auto it : g[i] )
                val[it.st] = max( val[it.st], val[i] + it.nd );
        }

    for( int i = 1; i <= n; i++ )
        fout << val[i] << '\n';

    return 0;
}
