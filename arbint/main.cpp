#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "arbint.in" );
ofstream fout ( "arbint.out" );
int n, q;
int a[200005];
int arb[800005];
int inters ( int la, int ra, int lb, int rb )
{
    if ( ra >= lb && la <= rb || rb >= la && lb <= ra )
        return 1;

    return 0;
}
int inter ( int la, int ra, int lb, int rb )
{
    if ( la >= lb && ra <= rb )
        return 1;

    return 0;
}
void update ( int father, int pos, int val, int l, int r )
{
    if ( l == r )
        {
            arb[father] = val;
            return;
        }

    int mid = ( l + r ) / 2;

    //stanga
    if ( inters ( l, mid, pos, pos ) )
        {
            update ( 2 * father, pos, val, l, mid );
            arb[father] = max ( arb[2 * father], arb[2 * father + 1] );
            return;
        }

    //dreapta
    update ( 2 * father + 1, pos, val, mid + 1, r );
    arb[father] = max ( arb[2 * father], arb[2 * father + 1] );
}
int query ( int father, int xl, int xr, int l, int r )
{
    if ( inter ( l, r, xl, xr ) )
        return arb[father];

    int sol_l = 0, sol_r = 0;
    int mid = ( l + r ) / 2;

    //stanga
    if ( inters ( xl, xr, l, mid ) )
        sol_l = query ( 2 * father, xl, xr, l, mid );

    //dreapta
    if ( inters ( xl, xr, mid + 1, r ) )
        sol_r = query ( 2 * father + 1, xl, xr, mid + 1, r );

    return max ( sol_l, sol_r );
}
void init ( )
{
    for ( int i = 2 * n + 1; i >= 1; i-- )
        arb[i / 2] += arb[i];
}
int main()
{
    fin >> n >> q;

    for ( int i = 1; i <= n; i++ )
        {
            fin >> a[i];
            update ( 1, i, a[i], 1, n );
            //arb[n + i] = a[i];
        }

    //init();

    for ( int i = 1; i <= q; i++ )
        {
            int t, a, b;
            fin >> t >> a >> b;

            if ( t == 1 )
                update ( 1, a, b, 1, n );
            else
                fout << query ( 1, a, b, 1, n ) << '\n';
        }

    return 0;
}
