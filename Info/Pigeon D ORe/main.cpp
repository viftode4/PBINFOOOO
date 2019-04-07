#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001];
int p[10] = {0, 1, 2, 4, 8, 16, 32};
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        cin >> a[i];

    sort( a + 1, a + n + 1 );

    while( n )
        {
            for( int i = 0; i <= 6; i++ )
                if( a[n] == p[i] )
                    {
                        cout << a[n];
                        return 0;
                    }

            n--;
        }

    return 0;
}
