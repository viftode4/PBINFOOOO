#include <bits/stdc++.h>
using namespace std;
int n, x;
int c[110];
int a[110];
void ciur()
{
    c[1] = c[0] = 1;

    for( int i = 4; i <= 100; i += 2 )
        c[i] = 1;

    for( int i = 3; i <= 100; i += 2 )
        if( c[i] == 0 )
            for( int j = i * 2; j <= 100; j += i )
                c[j] = 1;
}
int fr[101];
int main()
{
    ciur();
    cin >> n;
    cin >> x;
    int a = x;
    int  s = x, smin, b = 0;

    for( int i = 2; i <= n; i++ )
        {
            cin >> x;
            fr[x]++;

            a = min( x, a );
            s += x;
        }

    // cout << s << ' ' << a << ' ' << b << ' ';
    smin = s;
    s = s - a;

    for( int i = 100; i >= a; i-- )
        {
            if( fr[i] >= 1 && c[i] )
                {
                    s -= i;

                    for( int d = 1; d * d <= i; d++ )
                        if( i % d == 0 )
                            smin = min( s + a * ( i / d ) + i / ( i / d ), min( smin, s + a * d + i / d ) );

                    s += i;
                }
        }

    cout << smin;
    return 0;
}
