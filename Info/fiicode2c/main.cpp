#include <iostream>
using namespace std;
int a[3000001];
int n, x, y;
int main()
{
    cin >> n >> x >> y;

    for( int i = 0; i <= 2 * n; i++ )
        {
            a[i] = i % x;
            cout << a[i] << ' ';
        }

    return 0;
}
