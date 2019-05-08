#include <bits/stdc++.h>
using namespace std;
long long n, x, minsum, maxsum;
long long a[300005];
struct interval
{
    int s, d;
} maxi, mini;
int main()
{
    cin >> n >> x;

    for( int i = 1 ; i <= n; i++ )
        cin >> a[i];

    long long s = 0;
    int j = 0;

    // cout << maxsum << ' ' << maxi.s << ' ' << maxi.d << '\n';
    // cout << minsum << ' ' << mini.s << ' ' << mini.d << '\n';
    if( x < 0 )
        {
            for( int i = 1; i <= n; i++ )
                {
                    if( s > 0 || i == 1 )
                        {
                            s = a[i];
                            j = i;
                        }
                    else
                        s += a[i];

                    if( s < minsum )
                        {
                            minsum = s;
                            mini.s = j;
                            mini.d = i;
                        }
                }

            for( int i = mini.s; i <= mini.d; i++ )
                a[i] *= x;

            s = 0;
            j = 0;
        }

    if( x == 0 )
        {
            long long sp = 0;

            for( int i = 1; i <= n; i++ )
                {
                    if( s < 0 || i == 1 )
                        {
                            s = a[i];
                        }
                    else
                        s += a[i];

                    if( s > maxsum )
                        maxsum = s;
                }
        }

    for( int i = 1; i <= n; i++ )
        {
            if( s < 0 || i == 1 )
                s = a[i];
            else
                s += a[i];

            if( s > maxsum )
                maxsum = s;
        }

    if( x > 0 )
        cout << maxsum*x;
    else
        cout << maxsum;

    return 0;
}
