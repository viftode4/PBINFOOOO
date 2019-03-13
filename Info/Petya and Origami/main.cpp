#include <bits/stdc++.h>
using namespace std;
int n, k;
int main()
{
    cin >> n >> k;
    cout << ( 2 * n + k - 1 ) / k + ( 8 * n + k - 1 ) / k + ( 5 * n + k - 1 ) / k;
    return 0;
}
