#include <bits/stdc++.h>
using namespace std;
int n, s;
int a[105];
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        cin >> a[i];

    sort( a + 1, a + n + 1 );

    for( int i = 1; i <= n; i += 2 )
        s += a[i + 1] - a[i];

    cout << s;
    return 0;
}
