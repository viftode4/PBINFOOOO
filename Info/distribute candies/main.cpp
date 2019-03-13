#include <iostream>
using namespace std;
long long n, k, a[10001];
int main()
{
    cin >> n >> k;
    for ( int i = 1; i <= k; i++ )
    {
        a[i] = 1 + i % 2;
        n = n - 1 - i % 2;
    }
    for ( int i = 1; i <= k; i++ )
        a[i] += n / k;
    for ( int i = 1; i <= k; i++ )
        cout << a[i] << ' ';
    return 0;
}
