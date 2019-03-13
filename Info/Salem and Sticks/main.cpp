#include <bits/stdc++.h>
using namespace std;
int n, x, lg, lgmin = INT_MAX, tmin;
int a[1001];
int main()
{
    cin >> n;
    int st = INT_MAX;
    int dr = 0;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a[i];
            st = min( st, a[i] );
            dr = max( dr, a[i] );
        }

    for( int t = st; t <= dr; t++ )
        {
            lg = 0;

            for( int i = 1; i <= n; i++ )
                if( a[i] < t )
                    lg += ( t - 1 - a[i] );
                else if( a[i] > t )
                    lg += ( a[i] - ( t + 1 ) );

            if( lg < lgmin )
                {
                    lgmin = lg;
                    tmin = t;
                }
        }

    cout << tmin << ' ' << lgmin;

    return 0;
}
