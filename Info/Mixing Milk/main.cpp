#include <bits/stdc++.h>
using namespace std;
ifstream fin( "mixmilk.in" );
ofstream fout( "mixmilk.out" );
int a, b, c, pas;
int ca, cb, cc;
int main()
{
    fin >> ca >> a >> cb >> b >> cc >> c;
    pas = 0;

    for( int i = 1; i <= 100; i++ )
        {
            pas = pas % 3;
            //cout << a << ' ' << b << ' ' << c << endl;

            if( pas == 0 )
                {
                    b = a + b;
                    a = max( 0, b - cb );
                    b = min( cb, b );
                }
            else if( pas == 1 )
                {
                    c = c + b;
                    b = max( 0, c - cc );
                    c = min( c, cc );
                }
            else if( pas == 2 )
                {
                    a = a + c;
                    c = max( 0, a - ca );
                    a = min( ca, a );
                }

            pas++;
        }

    fout << a << '\n' << b << '\n' << c;
    return 0;
}
