#include <bits/stdc++.h>
using namespace std;
#define fin cin
#define fout cout
int m, o, dif;
double h, c, d, n, r2, r1;
int main()
{
    fin >> o >> m;
    fin >> h >> d >> c >> n;
    dif = ( 60 - m ) + ( 19 - o ) * 60;
    o = h / n;
    if ( ( int ) o < h / n )
        o++;
    r1 = o * c;
    h = h + dif * d;
    o = h / n;
    if ( o < h / n )
        o++;
    r2 = o * ( 80.0 / 100.0 * c );
    fout << fixed << setprecision ( 10 ) << min ( r1, r2 );
    return 0;
}
