#include <bits/stdc++.h>
using namespace std;
long long a, b, k;
int main()
{
    cin >> a >> b;
    int k = b / a;

    if( k * a < b )
        k++;

    cout << k;
    return 0;
}
