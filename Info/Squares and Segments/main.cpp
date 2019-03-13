#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    cin >> n;
    int k = 0;

    while( k * k <= n )
        k++;

    k--;
    long long s = k + k + ( n - k * k ) / k;

    if( ( n - k * k ) % k > 0 )
        s++;

    cout << s;
    return 0;
}
