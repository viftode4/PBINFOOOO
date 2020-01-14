#include <bits/stdc++.h>
using namespace std;
int a, b;
int main()
{
    cin >> a >> b;

    if( a == 9 && b == 1 )
        cout << 9 << ' ' << 10;
    else if( a == b )
        cout << a * 10 << ' ' << b * 10 + 1;
    else if( a + 1 = b )
        cout << a << ' ' << b;
    else
        cout << -1;

    return 0;
}
