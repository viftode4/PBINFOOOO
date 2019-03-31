#include <bits/stdc++.h>
using namespace std;
int n;
int x, t = 0;
long long sum;
int main()
{
    cin >> n;

    if( n < 10 )
        {
            cout << n;
            return 0;
        }

    sum = 1;

    while( n > 1000 )
        {
            //cout << n << ' ';

            if( n % 10 - 9 != 0 )
                t = 1;

            n /= 10;
            x = x * 10 + 9;
            sum *= 9;
        }

    n -= t;
    //cout << n;
    int nrmax = 0;

    while( n )
        {
            int cn = n;
            int p = 1;

            while( cn )
                {
                    p = p * ( cn % 10 );
                    cn /= 10;
                }

            nrmax = max( nrmax, p );
            n--;
        }

    cout << nrmax*sum;
    return 0;
}
