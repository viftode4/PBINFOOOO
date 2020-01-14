#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "volum.in" );
ofstream fout ( "volum.out" );
long long a[780][780], sum;
int use[780][780];
int n, m;
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
struct pos
{
    int i, j, val;
    pos () {};
    pos ( int a, int b, int c )
    {
        i = a;
        j = b;
        val = c;
    }
    bool operator< ( const pos& x ) const
    {
        return x.val < val;
    }
};
int in ( int i, int j )
{
    if ( i < 1 || i > n || j < 1 || j > m )
        return 0;

    return 1;
}
int ok ( int i, int j, int ui, int uj )
{
    if ( !in ( i, j ) )
        return 0;

    if ( use[i][j] )
        return 0;

    if ( a[i][j] > a[ui][uj] )
        return 0;

    return 1;
}
priority_queue<pos>pq;
void dfs ( int i, int j, int val )
{
    use[i][j] = 1;
    sum += val - a[i][j];

    for ( int d = 0; d < 4; d++ )
        if ( ok ( i + di[d], j + dj[d], i, j ) )
            dfs ( i + di[d], j + dj[d], val );
        else if ( in ( i + di[d], j + dj[d] ) && !use[i + di[d]][j + dj[d]] )
            {
                pos x ( i + di[d], j + dj[d], a[i + di[d]][j + dj[d]] );
                pq.push ( x );
            }

}
int main()
{
    fin >> n >> m;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j ++ )
            {
                fin >> a[i][j];
                a[i][j]++;

                if ( i == 1 || i == n || j == 1 || j == m )
                    {
                        pos x ( i, j, a[i][j] );
                        pq.push ( x );
                    }


            }

    while ( !pq.empty() )
        {
            pos x = pq.top();
            pq.pop();
            dfs ( x.i, x.j, x.val );
        }

    fout << sum;
    return 0;
}
