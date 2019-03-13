#include <bits/stdc++.h>
using namespace std;
long long n, x, y, ok;
struct p
{
    long long x, y;
} o[1010], a[1010][1010];
long long cauta( p v )
{

    for( int i = 1; i <= n; i++ )
    {
        ok = 0;

        for( int j = 1; j <= n; j++ )
            if( a[i][j].y == v.y && a[i][j].x == v.x  )
            {
                ok = 1;
                break;
            }

        if( ok == 0 )
            break;
    }

    return ok;
}
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        cin >> o[i].x >> o[i].y;

    for( int i = 1; i <= n; i++ )
    {
        cin >> x >> y;

        for( int j = 1; j <= n; j++ )
        {
            a[j][i].x = o[j].x + x;
            a[j][i].y = o[j].y + y;
        }
    }
    for( int i = 1; i <= n; i++ )
    {
        ok = cauta( a[1][i] );

        if( ok!=0 )
        {
            cout << a[1][i].x << ' ' << a[1][i].y;
            return 0;
        }
    }

    return 0;
}
