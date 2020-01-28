#include <iostream>

using namespace std;

int maxim, n, i;
int v[100000];

int main()
{
    cin >> n;

    for( i = 1; i <= n; i++ )
        cin >> v[i];

    maxim = 0;

    for( i = 1; i <= n; i++ )
        if( v[i] > maxim )
            maxim = v[i];

    cout << maxim;
    return 0;
}
