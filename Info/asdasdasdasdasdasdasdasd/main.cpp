#include <iostream>
using namespace std;
int n;
int Phi( int n )
{
    long long s = n, d = 3;

    if( n % 2 == 0 )
        {
            s /= 2;

            while( n % 2 == 0 )
                n /= 2;
        }

    while( n > 1 )
        {
            if( n % d == 0 )
                {
                    s = s * ( d - 1 ) / d;

                    while( n % d == 0 && n > 1 )
                        n /= d;
                }

            d += 2;

            if( d * d > n && n > 1 )
                d = n;
        }

    return s;
}
int main()
{
    cin >> n;
    cout << Phi( n );
    return 0;
}
