#include <bits/stdc++.h>
using namespace std;
int n,t,a,b,x;
int main()
{
    cin >> t;

    while( t-- )
        {
            cin >> n >> x >> a >> b;

            if( a > b )
                swap( a, b );

            while( x && a > 1 )
                {
                    a--;
                    x--;
                }

            while( x && b < n )
                {
                    b++;
                    x--;
                }

            cout << b - a<<'\n';
        }

    return 0;
}
