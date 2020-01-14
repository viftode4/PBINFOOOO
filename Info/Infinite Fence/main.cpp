#include <bits/stdc++.h>
using namespace std;
long long t, r, b, k;
int main()
{
    cin >> t;

    while( t )
        {
            cin >> r >> b >> k;
            long long g = __gcd( r, b );
            r /= g;
            b /= g;

            if( r > b )
                swap( r, b );

            if( ( k - 1 ) * r + 1LL < b )
                cout << "REBEL";
            else
                cout << "OBEY";

            cout << endl;
            t--;
        }

    return 0;
}
