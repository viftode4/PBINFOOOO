#include <bits/stdc++.h>
using namespace std;
int n, m, mini = 9999999, maxi, sum;
int main()
{
    cin >> n >> m >> sum;

    for( int i = 1; i <= n; i++ )
        {
            int x;
            cin >> x;
            mini = min( x, mini );
        }

    for( int i = 1; i <= m; i++ )
        {
            int x;
            cin >> x;
            maxi = max( x, maxi );
        }

    cout << max( sum, ( sum / mini )*maxi + sum % mini );
    return 0;
}
