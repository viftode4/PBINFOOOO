#include <bits/stdc++.h>

using namespace std;
int n, a[400010];
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        cin >> a[i];

    sort( a + 1, a + n + 1 );
    long long sum = 0;

    for( int i = 1; i <= n / 2; i++ )
        {
            long long s = a[i] + a[n - i + 1];
            sum += s * s;
        }

    cout << sum;
    return 0;
}
