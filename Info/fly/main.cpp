#include <bits/stdc++.h>
using namespace std;
int n, m;
double s;
int a[1005], b[1005];
int main()
{
    cin >> n >> m;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a[i];

            if( a[i] == 1 )
                {
                    cout << -1;
                    return 0;
                }
        }

    for( int i = 1; i <= n; i++ )
        {
            cin >> b[i];

            if( b[i] == 1 )
                {
                    cout << -1;
                    return 0;
                }
        }

    //m + x = a[1] * x;
    //m / ( a[1] - 1 ) = x;
    double x = m;
    x += ( double )( x / ( a[1] - 1.0 ) );

    for( int i = 2; i <= n; i++ )
        {
            x += ( double )( x / ( b[i] - 1.0 ) );
            x += ( double )( x / ( a[i] - 1.0 ) );
        }

    x += ( double )( x / ( b[1] - 1.0 ) );
    cout << setprecision( 10 ) << fixed << x - m;
    return 0;
}
