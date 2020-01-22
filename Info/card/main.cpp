#include <bits/stdc++.h>
using namespace std;
ifstream fin( "card.in" );
ofstream fout( "card.out" );
int n, m, x, y, k, t, nr, ul = INT_MAX, pr = INT_MAX, nrloc = INT_MAX;
int a[40][40];
int di[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dj[] = {1, 0, -1, 0, 1, -1, 1, -1};
vector<int>vec, sol;
void gen( int p, int x, int y, int cat )
{
    //vizitez xy
    int aux = a[x][y];
    a[x][y] = 0;

    if( cat == 0 )
        {
            //nrsol

            //nrpasi minim
            if( p < nrloc )
                {
                    sol = vec;
                    nr = 1;
                    nrloc = p;
                    ul = aux;
                    pr = t;
                }
            else if( p == nrloc )
                {
                    nr++;

                    //ultima casuta minima
                    if( ul > aux )
                        {
                            sol = vec;
                            ul = aux;
                            pr = t;
                        }
                    //prima casuta minima
                    else if( ul == aux && pr > t )
                        {
                            pr = t;
                            sol = vec;
                        }
                }

            //dezvizitez xy
            a[x][y] = aux;
            return;
        }

    //verif nr pasi
    if( p > k )
        {
            a[x][y] = aux;
            return;
        }

    for( int d = 0; d < 8; d++ )
        if( a[x + di[d]][y + dj[d]] )
            {
                int c = a[x + di[d]][y + dj[d]];

                if( p == 1 )
                    t = c;

                vec.push_back( c );
                //generare pct
                gen( p + 1, x + di[d], y + dj[d], cat - 2 * c );
                gen( p + 1, x + di[d], y + dj[d], cat - c / 2 );
                gen( p + 1, x + di[d], y + dj[d], cat + c );
                gen( p + 1, x + di[d], y + dj[d], cat - c );
                //devizitat
                vec.pop_back();
            }

    a[x][y] = aux;
}
int main()
{
    fin >> n >> m >> x >> y >> k;

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            fin >> a[i][j];

    gen( 1, x, y, a[x][y] );
    fout << nr << '\n';

    for( auto it : sol )
        fout << it << ' ';

    return 0;
}
