#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ( "bila.in" );
ofstream fout ( "bila.out" );
// vectori directie E, S, V, N
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
int n, m, a[20][20], is, js, sol, lg;
int border ( int x, int y )
{
    if ( x == 1 || x == n || y == 1 || y == m )
        return 1;

    return 0;
}
void parcurgere ( int x, int y )
{
    //crestem lungimea parcursa pana la x,y
    lg++;

    //daca am ajuns pe margine verificam daca e drum de lungime maxima
    if ( border ( x, y ) )
        {
            sol = max ( sol, lg );
            lg--;
            return;
        }

    for ( int d = 0; d < 4; d++ )

        //verificam pozitiile vecine daca sunt bune si daca sunt ne ducem in ele
        if ( a[x + di[d]][y + dj[d]] < a[x][y] )
            parcurgere ( x + di[d], y + dj[d] );

    //cand ne intoarcem scadem si lungimea drumului parcurs
    lg--;
}
int main()
{
    fin >> n >> m;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            fin >> a[i][j];

    fin >> is >> js;
    parcurgere ( is, js );
    fout << sol;
    return 0;
}
