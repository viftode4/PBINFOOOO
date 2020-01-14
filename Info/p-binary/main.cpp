#include <bits/stdc++.h>
using namespace std;
long long n, p, p2, x;
long long po[100000];
int ok( long long x )
{
    long long n1 = 0;
    long long nr = n - p * x;

    if( nr < 0 )
        return 0;

    //cout << nr << ' ';

    while( nr )
        {
            n1 += nr % 2;
            nr /= 2;
        }

    //cout << n1 << ' ' << x << '\n';

    if( n1 == 0 )
        return 0;

    if( n1 > x )
        return 0;

    return 1;
}
int main()
{
    cin >> n >> p;

    if( p == 0 )
        {
            int n1 = 0;

            while( n )
                {
                    n1 += n % 2;
                    n /= 2;
                }

            cout << n1;
            return 0;
        }

    if( p >= n )
        {
            cout << -1;
            return 0;
        }

    long long p2 = 1;
//
//    for( int i = 0; p2 <= n; i++ )
//        {
//            x++;
//            po[i] = p2 - p;
//            p2 = p2 * 2;
//        }
    long long r;

    if( p > 0 )
        r = ( n + p - 1 ) / p;
    else
        r = INT_MAX;

    long long l = 0;

    while( r - l > 1 )
        {
            long long mid = ( l + r ) / 2;
            //long long x = ( int )( log2( n - mid * p ) + 0.000001 );

            if( ok( mid ) )
                r = mid;
            else
                l = mid;
        }

    if( ok( r ) )
        cout << r << ' ';
    else
        cout << -1;

    return 0;
}
