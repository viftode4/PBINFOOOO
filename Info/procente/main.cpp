#include <bits/stdc++.h>
using namespace std;
ifstream fin( "procente.in" );
ofstream fout( "procente.out" );
int n, nr, s;
int viz[1];
char c;
void procent( double p, int x, double rest )
{
    if( rest )
        if( x == n && p == 1 )
            s++;

    if( x > n )
        return;

    for( int i = 1; i <= 200; i++ )
        procent( p *  i / 100, x + 1, 1 / ( p *  i / 100 ) );
}
int main()
{
    fin >> n;
    fin >> c >> nr;

    if( c == '-' )
        nr = nr * -1;

    double p = 100 + nr;
    p = p / 100;
    procent( p, 1, 1 / p );
    fout << s / ( n - 1 );
    return 0;
}
