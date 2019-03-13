#include <bits/stdc++.h>
using namespace std;
ifstream fin( "planting.in" );
ofstream fout( "planting.out" );
const int N = 1e5 + 10;
int n, x, y, nr, nrmax;
vector <int> g[N];
int main()
{
    fin >> n;

    if( n == 1 )
        fout << 1;
    else if( n == 2 )
        fout << 2;
    else if( n == 3 )
        fout << 3;
    else
        {
            for( int i = 1; i <= n - 1; i++ )
                {
                    fin >> x >> y;
                    g[x].push_back( y );
                    g[y].push_back( x );
                }

            for( int i = 1; i <= n; i++ )
                {
                    nr = g[i].size();
                    nrmax = max( nr, nrmax );
                }

            fout << 1 + nrmax;
        }

    return 0;
}
