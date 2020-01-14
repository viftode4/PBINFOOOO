#include <bits/stdc++.h>
using namespace std;
long long a, b, t, x, nr;
void gen( long long ca )
{
    if( ca > x )
        return;

    long long s = x ^ ca;

    if( ca <= x && s <= x && s >= a )
        nr++;

    gen( ca * 2 + 1 );
    gen( ca * 2 );
}
void numar()
{
    long long ca = a;
    gen( ca );
    a = ca;
}
int main()
{
    cin >> t;

    while( t )
        {
            t--;
            cin >> a >> b;
            x = 1;
            nr = 0;

            while( x <= b )
                {
                    cout<<x<<' '<<nr<<endl;
                    if( a <= x )
                        numar();

                    x = x * 2 + 1;
                }

            cout << nr;
        }

    return 0;
}
