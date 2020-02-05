#include <bits/stdc++.h>
using namespace std;
ifstream fin( "cartite.in" );
ofstream fout( "cartite.out" );
#define pb push_back
#define st first
#define nd second
#define mp make_pair
#define hh 10000
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
int cer, nrv, nrp;
int n, m, xc, yc;
int a[300][300];
int pp[300][300];
vector< pair< pair<int, int>, pair<int, int> > > portal;
vector<pair<int, int>>sol;
int usep[300];
int interior( int i, int j )
{
    if( i < 1 || i > n || j < 1 || j > m )
        return 0;

    return 1;
}
void lee( int i, int j, int r, int semn )
{
    queue<pair<int, int> >q;
    r++;
    q.push( mp( i, j ) );
    a[i][j] = 1 * semn;

    while( !q.empty() )
        {

            pair<int, int>p;
            p = q.front();
            q.pop();

            if( a[p.st][p.nd]*semn == r )
                continue;

            for( int d = 0; d < 4; d++ )
                {
                    int ci, cj;
                    ci = p.st + di[d];
                    cj = p.nd + dj[d];

                    if( interior( ci, cj ) && a[ci][cj] == 0 )
                        {
                            a[ci][cj] = a[p.st][p.nd] + 1 * semn;
                            q.push( mp( ci, cj ) );
                        }
                }
        }
}
void afisare()
{
    for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= m; j++ )
                fout << a[i][j] << ' ';

            fout << endl;
        }
}
pair<int, int> unde( pair<int, int>p )
{
    int x = a[p.st][p.nd];

    if( portal[x].st.st == p.st && portal[x].st.nd == p.nd )
        return mp( portal[x].nd.st, portal[x].nd.nd );
    else
        return mp( portal[x].st.st, portal[x].st.nd );
}
void dfs( int p, int x, int y )
{
    int ok = 1;

    for( int i = 0; i < nrp; i++ )
        if( !usep[i] )
            ok = 0;

    if( ok )
        {
            for( auto it : sol )
                fout << it.st << ' ' << it.nd << '\n';

            fout << sol[0].st << ' ' << sol[0].nd << '\n';
            exit( 0 );
        }

    for( int it = 0; it < nrp; it++ )
        {
            if( usep[it] )
                continue;

            int i = 0, j = 0;

            if( x == portal[it].st.st && y == portal[it].st.nd )
                {
                    i = portal[it].nd.st;
                    j = portal[it].nd.nd;
                }
            else if( x == portal[it].nd.st && y == portal[it].nd.nd )
                {
                    i = portal[it].st.st;
                    j = portal[it].st.nd;
                }

            if( i == 0 )
                continue;

            for( int d = 0; d < 4; d++ )
                {
                    int ci, cj;
                    ci = i + di[d];
                    cj = j + dj[d];
                }
        }

    usep[p] = 0;
}
int main()
{
    fin >> cer >> n >> m >> xc >> yc;
    fin >> nrv;

    for( int i = 1; i <= nrv; i++ )
        {
            int x, y, r;
            fin >> x >> y >> r;
            lee( x, y, r, -1 );
        }

    fin >> nrp;

    for( int i = 1; i <= nrp; i++ )
        {
            int ii, ij, fi, fj;
            fin >> ii >> ij >> fi >> fj;
            portal.pb( mp( mp( ii, ij ), mp( fi, fj ) ) );
        }

    lee( xc, yc, 99999, 1 );

    //afisare();
    if( cer == 1 )
        {

            int x, y, c = 99999;

            for( auto it : portal )
                if( a[it.st.st][it.st.nd] < c && a[it.st.st][it.st.nd] > 0 )
                    {
                        c = a[it.st.st][it.st.nd];
                        x = it.st.st;
                        y = it.st.nd;
                    }

            fout << x << ' ' << y << ' ' << c - 1;
            return 0;
        }

//    for( int i = 0; i < nrp; i++ )
//        {
//            pp[portal[i].st.st][portal[i].st.nd] = 1;
//            pp[portal[i].nd.st][portal[i].nd.nd] = 1;
//        }
//
//    int nr = 0;
//
//    for( int i = 0; i < nrp; i++ )
//        {
//            dfs( i, portal[i].st.st, portal[x].st.nd );
//            dfs( i, portal[i].nd.st, portal[x].nd.nd );
//        }

    return 0;
}
