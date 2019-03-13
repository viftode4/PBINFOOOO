#include <iostream>
using namespace std;
int n, v[100001], i, j;
int main()
{
    cin >> n;

    for( i = 1; i <= n; i++ )
        cin >> v[i];

    for( i = 1; i < n; i++ )
        for( j = i + 1; j <= n; j++ )
            if( v[i] > v[j] )
                swap( v[i], v[j] );

    if( n == 1 )
        cout << v[1] << ' ' << v[1] << endl << v[1] << ' ' << v[1];
    else if( n == 2 )
        cout << v[1] << ' ' << v[2] << endl << v[1] << ' ' << v[2];
    else if( n == 3 )
        cout << v[2] << ' ' << v[3] << endl << v[1] << ' ' << v[2];
    else
        cout << v[n-1] << ' ' << v[n] << endl << v[1] << ' ' << v[2];

    return 0;
}
