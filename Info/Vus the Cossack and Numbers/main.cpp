#include <bits/stdc++.h>
using namespace std;
int n, s;
int a[100005];
int ok[100005];
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            double x;
            cin >> x;
            a[i] = floor( x );

            if( floor( x ) == ceil( x ) )
                ok[i] = 1;

            s += a[i];
        }

    for( int i = 1; i <= n; i++ )
        {
            if( s < 0 && !ok[i] )
                {
                    a[i]++;
                    s++;
                }
        }

    for( int i = 1; i <= n; i++ )
        cout << a[i] << '\n';

    return 0;
}
