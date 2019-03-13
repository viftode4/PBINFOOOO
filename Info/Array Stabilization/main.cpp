#include <bits/stdc++.h>
using namespace std;
int n, a[100008], s;
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        cin >> a[i];

    sort( a + 1, a + n + 1 );
    s = a[n] - a[1];
    s = min( s, a[n] - a[2] );
    s = min( s, a[n - 1] - a[1] );
    cout << s;
    return 0;
}
