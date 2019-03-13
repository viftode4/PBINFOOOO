#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[50][2];
int main()
{
    cin >> n;
    a[1][1] = a[1][0] = 1;

    for( int i = 2; i <= n; i++ )
        {
            a[i][0] = a[i - 1][0] + a[i - 1][1];
            a[i][1] = a[i - 1][0];
        }

    cout << a[n][0] + a[n][1];
    cin >> k;

    int nr = 0;

    for( int i = n; i >= 1; i-- )
        {
            if( k <= 0 )
                cout << 0;
            else
                {
                    if( k <= a[i][0] )
                        {
                            cout << 0;
                            k -= a[i][0];
                        }
                    else
                        {
                            cout << 1;
                            k -= ( a[i][0] + a[i][1] );
                        }
                }
        }

    return 0;
}
