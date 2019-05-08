#include <bits/stdc++.h>
using namespace std;
int n, z;
int a[200005];
int ok( int x )
{
    for( int i = 1; i <= x; i++ )
        if( a[n - x + i] - a[i] < z )
            return 0;

    return 1;
}
int cauta()
{
    int l = 0;
    int r = n / 2 + 1;

    while( r - l > 1 )
        {
            int mid =  (l + r)  / 2;

            if( ok( mid ) )
                l = mid;
            else
                r = mid;
        }

    return l;
}
int main()
{
    cin >> n >> z;

    for( int i = 1; i <= n; i++ )
        cin >> a[i];

    sort( a + 1, a + n + 1 );

    cout << cauta();
    return 0;
}
