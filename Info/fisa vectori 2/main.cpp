#include <bits/stdc++.h>
using namespace std;
int n, v[100001], i, j;
int main()
{
    cin >> n;

    for( i = 1; i <= n; i++ )
        cin >> v[i];

    for( i = 2; i <= n - 1; i++ )
        if( v[i] == ( v[i - 1] + v[i + 1] ) / 2 )
            {
                for( j = i; j < n; j++ )
                    v[j] = v[j + 1];

                n--;
            }

    for( i = 1; i <= n; i++ )
        cout << v[i] << ' ';


    return 0;
}
