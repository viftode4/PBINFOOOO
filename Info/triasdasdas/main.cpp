#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull n;
ull f[510];
int main()
{
    cin >> n;
    f[3] = 6;

    for( int i = 4; i <= n; i++ )
        f[i] = f[i - 1] + ( i - 1 ) * i;

    cout << f[n];
    return 0;
}
