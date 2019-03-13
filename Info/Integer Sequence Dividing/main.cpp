#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    cin >> n;
    n %= 4;

    if( n == 0 || n == 3 )
        cout << 0;
    else
        cout << 1;

    return 0;
}
