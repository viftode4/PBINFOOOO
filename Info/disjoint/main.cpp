#include <bits/stdc++.h>
using namespace std;
ifstream fin( "disjoint.in" );
ofstream fout( "disjoint.out" );
int n, m;
int o, x, y;
int nod[100005];
vector<int> multimi[100005];
void reunire( int x, int y )
{
    if( multimi[x].size() > multimi[y].size() )
        swap( x, y );

    multimi[y].insert( multimi[y].end(), multimi[x].begin(), multimi[x].end() );

    for( auto it : multimi[x] )
        nod[it] = y;

    multimi[x].erase( multimi[x].begin(), multimi[x].end() );
}
int main()
{
    fin >> n >> m;

    for( int i = 1; i <= n; i++ )
        {
            nod[i] = i;
            multimi[i].push_back( i );
        }

    for( int i = 1; i <= m; i++ )
        {
            fin >> o >> x >> y;

            if( o == 1 )
                reunire( nod[x], nod[y] );
            else
                {
                    if( nod[x] == nod[y] )
                        fout << "DA\n";
                    else
                        fout << "NU\n";
                }
        }

    return 0;
}
