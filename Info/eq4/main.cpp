#include <bits/stdc++.h>
using namespace std;
ifstream fin( "eq4.in" );
ofstream fout( "eq4.out" );
int cer, a, b, E;
string e;
int x,  y,  z, t, l;
int main()
{
    fin >> cer >> e >> a >> b >> E;
    int semn = 1;
    int p = 0;

    for( int i = 0; e[i]; i++ )
        {
            if( e[i] == '+' )
                {
                    l = l + p * semn;
                    semn = 1;
                    p = 0;
                }
            else if( e[i] == '-' )
                {
                    l = l + p * semn;
                    semn = -1;
                    p = 0;
                }
            else if( e[i] >= '0' && e[i] <= '9' )
                p = p * 10 + ( e[i] - '0' );
            else if( e[i] == 'x' )
                {
                    if( p == 0 )
                        p = 1;

                    x = x + semn * p;
                    p = 0;
                }
            else if( e[i] == 'y' )
                {
                    if( p == 0 )
                        p = 1;

                    y = y + semn * p;
                    p = 0;
                }
            else if( e[i] == 'z' )
                {
                    if( p == 0 )
                        p = 1;

                    z = z + semn * p;
                    p = 0;
                }
            else if( e[i] == 't' )
                {
                    if( p == 0 )
                        p = 1;

                    t = t + semn * p;
                    p = 0;
                }
        }

    if( p > 0 )
        l = l + p;

    fout << x << ' ' << y << ' ' << z << ' ' << t << ' ' << l << ' ';

    if( cer == 1 )
        {
            fout << x + y + z + t + l;
        }

    return 0;
}
