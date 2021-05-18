#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
using namespace std;
int n, m, c, a[100005], x, y, use[100005];
vector< int >g[100005];
vector< int >t[100005];
queue<int>q;
int sola[100005], solb[100005];
void dfs0 ( int v )
{
    sola[v] = 0;

    for ( auto it : g[v] )
        if ( !use[it] )
            {
                use[it] = 1;
                dfs0 ( it );
            }

    for ( auto it : g[v] )
        use[it] = 0;

    g[v].clear();
}
int main()
{
    cin >> c;
    cin >> n >> m;

    for ( int i = 1; i <= n; i++ )
        {
            cin >> a[i];
            sola[i] = 1;
            solb[i] = 1;
        }

    for ( int i = 1; i <= m; i++ )
        {
            cin >> x >> y;
            g[x].pb ( y );
            g[y].pb ( x );
            t[x].pb ( y );
            t[y].pb ( x );

            if ( a[x] == 0 || a[y] == 0 )
                {
                    dfs0 ( x );
                }
        }

    //cout << endl;
    if ( c == 1 )
        {
            for ( int i = 1; i <= n; i++ )
                cout << sola[i];
        }
    else
        {
            for ( int i = 1; i <= n; i++ )
                use[i] = 0;

            for ( int i = 1; i <= n; i++ )
                {
                    if ( a[i] == 1 )
                        q.push ( i );

                    use[i] = 1;
                }

            while ( !q.empty() )
                {
                    int x = q.front();
                    q.pop();
                    int ok = 0, ok1 = 0;

                    for ( auto it : t[x] )
                        {
                            if ( sola[it] == 0 )
                                ok1 = 1;
                            else if ( sola[it] == 1 )
                                ok = 1;
                        }

                    if ( !ok  && ok1 )
                        solb[x] = 0;
                }

            for ( int i = 1; i <= n; i++ )
                cout << solb[i];
        }

    return 0;
}
