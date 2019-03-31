#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010];
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        cin >> a[i];

    int i = n - 1;

    while( a[i] == a[i + 1] )
        i--;

    cout << i;
    return 0;
}
