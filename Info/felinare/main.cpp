#include <bits/stdc++.h>
#define pb push_back
using namespace std;

ifstream fin( "felinare.in" );
ofstream fout( "felinare.out" );

vector<int>g[9000];
vector<int>t[9000];
//1 primul bec | intra in nod
//2 al doilea bec | ies din nod
int n, m;
int f[9000][4], nr;
int use[9000];
void dfs( int i )
{
    use[i] = 1;
    int ok = 1;

    if( !f[i][1] )
        {
            for( auto it : g[i] )
                if( f[it][1] == 1 )
                    {
                        ok = 0;
                        break;
                    }

            if( ok )
                {
                    nr++;
                    f[i][1] = 1;
                }

            ok = 1;
        }


    if( !f[i][2] )
        {
            for( auto it : t[i] )
                if( f[it][1] == 1 )
                    {
                        ok = 0;
                        break;
                    }

            if( ok )
                {
                    nr++;
                    f[i][2] = 1;
                }
        }


    for( auto it : g[i] )
        if( !use[it] )
            dfs( it );
}
int main()
{
    fin >> n >> m;

    for( int i = 1; i <= m; i++ )
        {
            int x, y;
            fin >> x >> y;
            g[x].pb( y );
            t[y].pb( x );
        }

    for( int i = 1; i <= n; i++ )
        {
            if( t[i].size() == 0 )
                f[i][2] = 1, nr++;

            if( g[i].size() == 0 )
                f[i][1] = 1, nr++;
        }

    for( int i = 1; i <= n; i++ )
        dfs( i );

    fout << nr << '\n';

    for( int i = 1; i <= n; i++ )
        {
            if( f[i][1] && f[i][2] )
                fout << "3\n";
            else if( f[i][1] && !f[i][2] )
                fout << "1\n";
            else if( !f[i][1] && f[i][2] )
                fout << "2\n";
            else
                fout << "0\n";
        }

    return 0;
}
