#include <bits/stdc++.h>
using namespace std;
int n, amax, q, nr;
int v[5010];
int a[5010];
struct painter
{
    int l, r;
} p[5010];

int main()
{
    cin >> q >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> p[i].l >> p[i].r;
            a[p[i].l]++;
            a[p[i].r + 1]--;
        }

    for( int i = 1; i <= n; i++ )
        a[i] += a[i - 1];

    for( int i = 1; i < n; i++ )
        for( int j = i + 1; j <= n; j++ )
            {
                painter a, b, c;
                a = p[i];
                b = p[j];
                c.r = 0;
                c.l = 0;

                if( a.l > b.l )
                    swap( a, b );

                if( a.r >= b.l )
                    {
                        c.l = b.l;

                        if( a.l >= b.r )
                            c.r = b.r;
                        else
                            c.r = a.r;
                    }

                if( c.r != 0 )
                    {
                        a.r = c.l - 1;
                        b.l = c.r + 1;
                    }

                for( int =; i <= )
                }

    return 0;
}
