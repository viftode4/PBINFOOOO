#include <bits/stdc++.h>
using namespace std;
int n, v;
int x, sum;
int main()
{
    cin >> n >> v;
    sum = min( v, n - 1 );

    for( int i = 2; i <= n - v; i++ )
        sum += i;

    cout << sum;
    return 0;
}
