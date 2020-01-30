#include <bits/stdc++.h>

using namespace std;

ifstream fin( "modernizare.in" );
ofstream fout( "modernizare.out" );

int viz[100001], n, m, fond;

struct val
{

    int nmin, nmax, cost;
};

vector<val> muchie;

bool comp( val a, val b )
{

    if( a.nmin == b.nmin )
        {

            if( a.nmax == b.nmax )

                return a.cost < b.cost;

            return a.nmax < b.nmax;
        }

    return a.nmin < b.nmin;
}

int main()
{

    fin >> n >> m >> fond;

    vector<int> nod[n + 1];

    for( int i = 1; i <= m; i++ )
        {

            int x, y, c;
            fin >> x >> y >> c;

            nod[x].push_back( y );
            nod[y].push_back( x );

            muchie.push_back( {x, y, c} );
        }

    int coada[n + 1], ultim = 0, prim = 1;
    coada[++ultim] = 1;
    viz[1] = 1;

    while( prim <= ultim )
        {

            int cur = coada[prim];

            for( auto i : nod[cur] )

                if( viz[i] == 0 )
                    {

                        coada[++ultim] = i;

                        viz[i] = viz[cur] + 1;
                    }

            prim++;
        }

    for( int i = 0; i < m; i++ )
        {

            int x = viz[muchie[i].nmin], y = viz[muchie[i].nmax];

            muchie[i].nmin = min( x, y );

            muchie[i].nmax = max( x, y );
        }

    sort( muchie.begin(), muchie.end(), comp );

    int s = 0;

    for( auto i : muchie )

        if( fond - i.cost >= 0 )
            {

                s++;

                fond -= i.cost;
            }
        else
            break;


    fout << s;

    return 0;
}
