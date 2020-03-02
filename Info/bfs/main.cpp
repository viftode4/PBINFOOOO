#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "bfs.in" );
ofstream fout( "bfs.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
int n, m, s;
int use[100005];
vector<int> g[100005];
void bfs( int x )
{
    queue<int>q;
    q.push( x );
    use[x] = 1;

    while( !q.empty() )
        {
            int t = q.front();
            q.pop();

            for( auto it : g[t] )
                if( !use[it] )
                    {
                        use[it] = use[t] + 1;
                        q.push( it );
                    }
        }
}
int main()
{
    fast();
    fin >> n >> m >> s;

    for( int i = 1; i <= m; i++ )
        {
            int x, y;
            fin >> x >> y;
            g[x].pb( y );
            //g[y].pb( x );
        }

    bfs( s );

    for( int i = 1; i <= n; i++ )
        fout << use[i] - 1 << ' ';

    return 0;
}
