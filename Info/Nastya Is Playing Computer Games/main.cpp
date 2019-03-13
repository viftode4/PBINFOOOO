#include <bits/stdc++.h>
using namespace std;
int n, k;
int s;
int main()
{
    cin >> n >> k;
    s += min( n - k, k - 1 );
    s += 6;
    s += 3 * ( n - 2 );
    cout<<s;
    return 0;
}
