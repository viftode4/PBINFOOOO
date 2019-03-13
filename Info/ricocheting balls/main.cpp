#include <bits/stdc++.h>
using namespace std;
#define fin cin
#define fout cout
int n, a[100010];
int maxi = 0, dmin = 1000000000, d, ds, dd;
int main()
{
    fin >> n;
    for ( int i = 1; i <= n; i++ )
    {
        fin >> a[i];
        maxi = max ( a[i], maxi );
    }
    int st = 1, dr = maxi, mij ;
    while ( st <= dr )
    {
        mij = ( st + dr ) / 2;
        d = 0;
        ds = 0;
        dd = 0;
        for ( int i = 1; i <= n; i++ )
        {
            d = d + fabs ( mij - a[i] );
            ds = ds + fabs ( ( st + mij ) / 2 - a[i] );
            dd = dd + fabs ( ( dr + mij ) / 2 - a[i] );
        }
        if ( d >= ds && ds < dd )
            dr = mij;
        else if ( d >= dd && dd < ds )
            st = mij;
        else if ( ds == dd )
            st++, dr--;
    }
    fout << d;
    return   0;
}
