#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int main()
{

    cin >> n;

    for( int i = 1; i <= n; i++ )
        cin >> a[i];

    sort( a + 1, a + n + 1 );
    int ini = 1, cate = 0;

    for( int i = 1; i <= n; i++ )
        if( ini <= a[i] )
            {
                ini++;
                cate++;
            }

    cout << cate;
    return 0;
}
