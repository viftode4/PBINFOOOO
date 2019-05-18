#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[310];
int prime( int x )
{
    if(x==2)
        return 1;
    if( x % 2 == 0 )
        return 0;

    if( x == 0 || x == 1 )
        return 0;

    for( int d = 3; d * d <= x; d += 2 )
        if( x % d == 0 )
            return 0;

    return 1;
}
int main()
{
    cin >> t;

    while( t )
        {
            cin >> n;
            cin >> a[1];

            if( n == 1 )
                {
                    if( !prime( a[1] ) )
                        cout << -1 << '\n';
                    else
                        cout << a[1]*a[1] << '\n';

                    t--;
                    continue;
                }

            map<int, int>m;
            m[a[1]] = 1;
            long long ans = a[1];

            for( int i = 2; i <= n; i++ )
                {
                    cin >> a[i];
                    m[a[i]] = 1;
                    ans = ( ( ( ans * a[i] ) ) / ( __gcd( ans, 1LL * a[i] ) ) );

                }

            int ok = 0;

            for( int i = 1; i <= n; i++ )
                if( !m[ans / a[i]] )
                    {
                        ok = 1;
                        break;
                    }

            for( int i = 1; i <= n; i++ )
                if( a[i] == ans || a[i] == 1 )
                    {
                        ok = 1;
                        break;
                    }

            if( !ok )
                cout << ans << '\n';
            else
                cout << -1 << '\n';

            t--;
        }

    return 0;
}
