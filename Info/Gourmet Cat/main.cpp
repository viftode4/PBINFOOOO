#include <bits/stdc++.h>
using namespace std;
int a, b, c, nrsapt, cat;
int main()
{
    cin >> a >> b >> c;
    nrsapt = min( {a / 3, b / 2, c / 2} );
    a -= 3 * nrsapt;
    b -= 2 * nrsapt;
    c -= 2 * nrsapt;

    for( int i = 0; i < 7; i++ )
        {
            int ca = a, cb = b, cc = c;
            int z = i, nr = 0;

            while( true )
                {
                    nr++;

                    if( z == 0 || z == 3 || z == 6 )
                        {
                            if( ca == 0 )
                                break;

                            ca--;
                        }
                    else if( z == 1 || z == 5 )
                        {
                            if( cb == 0 )
                                break;

                            cb--;
                        }
                    else
                        {
                            if( cc == 0 )
                                break;

                            cc--;
                        }

                    z = ( z + 1 ) % 7;
                }

            cat = max( cat, nr-1 );
        }

    cout << 7 * nrsapt + cat;
    return 0;
}
