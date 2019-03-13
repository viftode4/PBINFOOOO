#include <iostream>
using namespace std;
int n, k, i, j, v[1001];
int main()
{
    cin >> n >> k;

    for( i = 1; i <= k; i++ )
        cin >> v[i];

    for( i = 1; i < k; i++ )
        for( j = i + 1; j <= k; j++ )
            if( v[i] > v[j] )
                swap( v[i], v[j] );

    for( i = 1; i <= k; i++ )
        cout << v[i] << ' ';

    for( i = 1; i <= n - k; i++ )
        cin >> v[i];

    for( i = 1; i < n - k; i++ )
        for( j = i + 1; j <= n - k; j++ )
            if( v[i] < v[j] )
                swap( v[i], v[j] );

    for( i = 1; i <= n - k; i++ )
        cout << v[i] << ' ';

    return 0;
}
