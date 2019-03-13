#include <bits/stdc++.h>
using namespace std;
double a, b;
int n, nra, nrb;
double smax, sa, sb;
int main()
{
    cin >> a >> b >> n;

    for( int i = 1; i <= n; i++ )
        {
            sa = ( ( nra + 1 ) * a - ( nra + 1 ) * ( nra + 1 ) + nrb * b - nrb * nrb ) * 1.0 + 0.000000001;
            sb = ( ( nrb + 1 ) * b - ( nrb + 1 ) * ( nrb + 1 ) + nra * a - nra * nra ) * 1.0 + 0.000000001;

            if( sa >= sb && smax <= sa )
                {
                    smax = sa * 1.0 + 0.000000001;
                    nra++;
                }

            else if( sa < sb && smax < sb )
                {
                    smax = sb * 1.0 + 0.000000001;
                    nrb++;
                }
        }

    cout << fixed << setprecision( 2 ) << ' ' << smax + 0.000000001 << '\n' << nra << ' ' << nrb;
    return 0;
}
