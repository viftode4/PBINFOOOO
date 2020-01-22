#include <bits/stdc++.h>
using namespace std;
int t;
int n, k, x;
int main()
{
    cin>>t;
    while( t-- )
        {
            cin >> n >> k;
            int mini = INT_MAX;
            int maxi = 0;

            for( int i = 1; i <= n; i++ )
                {
                    cin >> x;

                    mini = min( mini, x);
                    maxi = max( maxi, x );
                }

            if( maxi - mini > 2*k )
                cout << -1 << '\n';
            else
                cout << mini + k << '\n';
        }

    return 0;
}
