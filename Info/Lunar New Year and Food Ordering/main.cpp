#include <bits/stdc++.h>
using namespace std;
long long n, m, v;
struct food
{
    long long a, c, i;
} a[100010], b[100010];
int cond( food a, food b )
{
    if( a.c > b.c )
        return 1;
    else if( a.c == b.c && a.i > b.i )
        return 1;

    return 0;
}
int main()
{
    cin >> n >> m;

    for( int i = 1; i <= n; i++ )
        cin >> a[i].a;


    for( int i = 1; i <= n; i++ )
        cin >> a[i].c;

    for( int i = 1; i <= n; i++ )
        {
            a[i].i = i;
            b[i] = a[i];
        }

    sort( a + 1, a + n + 1, cond );

    for( int i = 1; i <= n; i++ )
        b[a[i].i].i = i;

    /*for( int i = 1; i <= n; i++ )
        cout << b[i].c << ' ' << b[i].i << ' ' << a[i].c << ' ' << a[i].i << endl;;
    */
    long long t, d;
    v = n;

    for( int i = 1; i <= m; i++ )
        {
            cin >> t >> d;
            unsigned long long  sum = 0, r = 0;

            if( b[t].a >= d )
                {
                    b[t].a -= d;
                    a[b[t].i].a -= d;
                    sum += b[t].c * d;
                    // cout << sum << ' ';
                }
            else
                {
                    r = d - b[t].a;
                    sum += b[t].a * b[t].c;
                    b[t].a = 0;
                    a[b[t].i].a = 0;
                    //cout << sum << ' ';

                    while( r > 0 && v > 0 )
                        {
                            if( a[v].a > r )
                                {
                                    sum += r * a[v].c;
                                    a[v].a -= r;
                                    b[a[v].i].a -= r;
                                    r = 0;
                                }
                            else
                                {
                                    sum += a[v].c * a[v].a;
                                    r -= a[v].a;
                                    a[v].a = 0;
                                    b[a[v].i].a = 0;
                                    v--;
                                }

                            //cout << sum << ' ';
                        }
                }

            if( v == 0 && r > 0 )
                cout << 0 << '\n';
            else
                cout << sum << '\n';

        }

    return 0;
}
