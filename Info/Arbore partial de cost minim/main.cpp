#include <bits/stdc++.h>
using namespace std;
ifstream fin( "apm.in" );
ofstream fout( "apm.out" );
#define endl '\n'
int n, m, c, sum, x, y;
//graf
int use[200005];
int solx[200005], v;
int soly[200005];
struct pct
{
    int cost;
    int n;
    pct( int a, int b )
    {
        n = a;
        cost = b;
    }
    pct() {};
};
vector<pct>g[200005];
//muchii
struct muchii
{
    int x, y, cost;
    muchii( int a, int b, int c )
    {
        if( a > b )
            swap( a, b );

        x = a;
        y = b;
        cost = c;
    }
    muchii() {};
};
bool operator<( const muchii&a, const muchii&b )
{
    return a.cost > b.cost;
}
priority_queue<muchii> q;
int main()
{
    fin >> n >> m;

    for( int i = 1; i <= n; i++ )
        {
            fin >> x >> y >> c;
            g[x].push_back( pct( y, c ) );
            g[y].push_back( pct( x, c ) );
        }

    use[1] = 1;

    for( auto it : g[1] )
        q.push( muchii( 1, it.n, it.cost ) );

    while( !q.empty() )
        {
            muchii x;
            x = q.top();
            q.pop();

            //daca un nod nu e folosit
            if( !use[x.x] || !use[x.y] )
                {
                    int i, f;

                    if( !use[x.y] )
                        i = x.x, f = x.y;
                    else
                        i = x.y, f = x.x;

                    //solutia
                    v++;
                    solx[v] = i;
                    soly[v] = f;
                    sum += x.cost;
                    //il folosim bruh
                    use[f] = 1;

                    for( auto it : g[f] )
                        q.push( muchii( f, it.n, it.cost ) );
                }
        }

    fout << sum << endl;
    fout << v << endl;

    for( int i = 1; i <= v; i++ )
        fout << solx[i] << ' ' << soly[i] << endl;

    return 0;
}
