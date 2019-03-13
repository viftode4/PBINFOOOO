#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int use[200010];
vector <int> a[200010], sol;
void bfs( int i )
{
    priority_queue<int, vector<int>, greater<int>> q;
    q.push( i );
    use[i] = 1;

    while( !q.empty() )
        {
            int f = q.top();
            q.pop();
            sol.push_back( f );

            for( auto it : a[f] )
                if( !use[it] )
                    {
                        q.push( it );
                        use[it] = 1;
                    }
        }
}
int main()
{
    cin >> n >> m;

    for( int i = 1; i <= m; i++ )
        {
            cin >> x >> y;
            a[x].push_back( y );
            a[y].push_back( x );
        }


    bfs( 1 );

    for( auto it : sol )
        cout << it << ' ';

    return 0;
}
