#include <iostream>
using namespace std;
int n, a[10001], i;
int fr;
int main() {
    cin >> n;

    for ( i = 1; i <= n; i++ )
        cin >> a[i];

    for ( int i = 1; i < n; i++ )
        if ( a[i] == a[n] )
            fr++;

    cout << fr;
    return 0;
}
