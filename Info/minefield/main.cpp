#include <bits/stdc++.h>
using namespace std;
int n, x, elmin, s;
int a[110];
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        cin >> a[i];

    sort( a + 1, a + n + 1 );

    /*for( int i = 1; i <= n; i++ )
        cout << a[i] << ' ';*/

    while( n > 3 )
        {
            int s1 = 0, s2 = 0;
            s1 = a[n] + a[1] + a[n - 1] + a[1];
            s2 = a[2] + a[1] + a[n] + a[2];
           // cout << s1 << ' ' << s2 << '\n';
            s = s + min( s1, s2 );
            n -= 2;
        }

    if( n == 2 )
        s = s + a[2];
    else
        s = s + a[3] + a[1] + a[2];


    cout << s;
    return 0;
}
