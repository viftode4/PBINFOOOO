#include <bits/stdc++.h>
using namespace std;
int n;
int a[400000];
int x[400000];
void xr( int l, int r )
{
    int mid = ( l + r - 1 ) / 2;
    int x1 = a[l], x2 = a[r];
    cout << l << ' ' << r << ' ';

    for( int i = l + 1; i <= mid; i++ )
        x1 = x1 ^ a[i];

    for( int i = mid + 1; i < r; i++ )
        x2 = x2 ^ a[i];

    cout << x1 << ' ' << x2 << endl;
}
int main()
{
    cin >> n;
    cin >> a[1];
    x[1] = a[1];

    for( int i = 2; i <= n; i++ )
        {
            cin >> a[i];
            x[i] = x[i - 1] ^ a[i];
        }

    for( int i = 1; i < n; i++ )
        {
            for( int j = i + 1; j <= n; j++ )
                {
                    if( ( i + j - 1 ) % 2 == 0 )
                        xr( i, j );
                }
        }

    for( int i = 1; i <= n; i++ )
        cout << x[i] << ' ';

    return 0;
}
