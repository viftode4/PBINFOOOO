#include <bits/stdc++.h>
using namespace std;
long long n, a, b, c = 1;
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a >> b;

            cout << ( long long )( ( a - 1 ) * 9 + b )*c << '\n';
        }

    return 0;
}
