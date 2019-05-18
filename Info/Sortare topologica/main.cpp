#include <bits/stdc++.h>
using namespace std;
ifstream fin( "sortaret.in" );
ofstream fout( "sortaret.out" );
int grad[50005];
int n, m, x, y;
vector <int> g[50005];
queue<int> q;
vector<int> sol;
int main()
{
    fin >> n >> m;

    for( int i = 1; i <= m; i++ )
        {
            fin >> x >> y;
            g[x].push_back( y );
            grad[y]++;
        }

    for( int i = 1; i <= n; i++ )
        if( !grad[i] )
            q.push( i );

    while( !q.empty() )
        {
            int x = q.front();
            q.pop();
            sol.push_back( x );

            for( auto it : g[x] )
                {
                    grad[it]--;

                    if( grad[it] == 0 )
                        q.push( it );
                }
        }

    for( auto it : sol )
        fout << it << ' ';

    return 0;
}
