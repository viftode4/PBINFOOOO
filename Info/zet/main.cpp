#include <bits/stdc++.h>
using namespace std;
ifstream fin( "zet.in" );
ofstream fout( "zet.out" );
int n, k, p;
int main()
{
    fin >> p >> k >> n;

    if( p == 1 )
        {
            fout << k*k - 2;
            return 0;
        }

    long long a = k, b, c;
    b = k * k - 2;
    int nr = 2;

    while( nr < n )
        {
            c = ( k - 2 ) * a + b + ( b - a ) * ( k - 1 );
            a = b;
            b = c;
            nr++;
        }

    fout << b;
    return 0;
}
