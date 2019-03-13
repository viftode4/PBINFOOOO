#include <bits/stdc++.h>
using namespace std;
int a, b, m;
int main()
{
    cin >> a >> b >> m;
    int nr = m - 1 - a % m;

    if( a + nr > b )
        cout << b % m;
    else
        cout << m - 1;

    return 0;
}
