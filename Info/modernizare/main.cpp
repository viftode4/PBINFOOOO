#include <bits/stdc++.h>
using namespace std;
ifstream fin( "modernizare.in" );
ofstream fout( "modernizare.out" );

#define all(x) (x).begin() , (x).end()
#define pb push_back
#define mp make_pair
#define st first
#define nd second

struct strada
{
    int v, x, i;
    strada()
    {
        v = 0;
        x = 0;
        i = 0;
    }
    strada( int a, int b, int c )
    {
        x = a;
        v = b;
        i = c;
    }
};

int n, m, f;
int use[100005];
int usestr[100005];

vector<strada>nod[100005];
vector < pair<int, pair<int, int> > >strazi[100005];

void bfs( int x )
{
    queue<strada>q;
    q.push( strada( x, 0, 0 ) );
    use[x] = 1;

    while( !q.empty() )
        {
            strada t = q.front();
            q.pop();
            int y = t.x;

            for( auto it : nod[y] )
                if( !use[it.x] )
                    {
                        use[it.x] = use[y] + 1;
                        q.push( strada( it.x, 0, 0 ) );
                    }
        }
}
void str( int x )
{
    queue<int>q;
    q.push( x );

    while( !q.empty() )
        {
            int y = q.front();
            q.pop();

            for( auto it : nod[y] )
                if( !usestr[it.i] )
                    {
                        usestr[it.i] = min( use[y], use[it.x] );
                        strazi[usestr[it.i]].pb( mp( min( use[y], use[it.x] ), mp( max( use[y], use[it.x] ), it.v ) ) );

                        q.push( it.x );
                    }
        }
}
int modernizare( int x )
{
    if( f == 0 || strazi[x].size() == 0 )
        return 0;

    sort( all( strazi[x] ) );
    int nr = 0;

    for( auto it : strazi[x] )
        if( f - it.nd.nd >= 0 )
            {
                nr++;
                f -= it.nd.nd;
            }
        else
            break;

    if( nr == strazi[x].size() )
        return nr + modernizare( x + 1 );
    else
        return nr;
}
int main()
{
    fin >> n >> m >> f;

    for( int i = 1; i <= m; i++ )
        {
            int x, y, v;
            fin >> x >> y >> v;
            nod[y].pb( strada( x, v, i ) );
            nod[x].pb( strada( y, v, i ) );
        }

    bfs( 1 );
    str( 1 );
    fout << modernizare( 1 );
    return 0;
}
