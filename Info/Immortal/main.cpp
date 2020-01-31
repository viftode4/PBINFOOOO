#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define st first
#define nd second

ifstream fin( "immortal.in" );
ofstream fout( "immortal.out" );

vector < pair<int, int> >sola, solb;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
int a[30][30];
int n, m, k;

int interior( int i, int j )
{
    if( i < 1 || i > n || j < 1 || j > m )
        return 0;

    return 1;
}
void bkt( int x )
{
    if( x == k )
        {
            for( int i = 0; i < x - 1; i++ )
                fout << sola[i].st << ' ' << sola[i].nd << ' ' << solb[i].st << ' ' << solb[i].nd << '\n';

            exit( 0 );
        }

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            for( int d = 0; d < 4; d++ )
                if( a[i][j] && a[i + di[d]][j + dj[d]] && interior( i + di[d] * 2, j + dj[d] * 2 ) && !a[i + di[d] * 2][j + dj[d] * 2] )
                    {
                        sola.pb( mp( i, j ) );
                        solb.pb( mp( i + di[d] * 2, j + dj[d] * 2 ) );
                        a[i][j] = 0;
                        a[i + di[d]][j + dj[d]] = 0;
                        a[i + di[d] * 2][j + dj[d] * 2] = 1;
                        bkt( x + 1 );
                        sola.pop_back();
                        solb.pop_back();
                        a[i][j] = 1;
                        a[i + di[d]][j + dj[d]] = 1;
                        a[i + di[d] * 2][j + dj[d] * 2] = 0;
                    }
}
int main()
{
    fin >> n >> m >> k;

    for( int i = 1; i <= k; i++ )
        {
            int x, y;
            fin >> x >> y;
            a[x][y] = 1;
        }

    bkt( 1 );
    return 0;
}
