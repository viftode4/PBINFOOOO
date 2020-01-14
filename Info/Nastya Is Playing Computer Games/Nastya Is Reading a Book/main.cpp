#include <bits/stdc++.h>
using namespace std;
int n;
int l, r;
int k, m;
int a[100010];
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> l >> r;
            a[r + 1]++;
            m = max( m, r );
        }

    for( int i = 1; i <= m + 1; i++ )
        a[i] += a[i - 1];

    cin >> k;
    cout << a[m + 1] - a[k] ;
    return 0;
}
