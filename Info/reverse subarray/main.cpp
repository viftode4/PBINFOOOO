#include <iostream>
#include <algorithm>
using namespace std;
int n, a[10001], b[10001], c[100001], x, y, nr, ok;
int main() {
    cin >> n;
    for ( int i = 1; i <= n; i++ ) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort ( a + 1, a + n + 1 );
    for ( int i = 1; i <= n; i++ ) {
        if ( a[i] != b[i] ) {
            c[i] = 1;
            nr++;
        }
    }
    if ( nr == 0 )
        cout << n << endl << 1 << ' ' << 1;
    else {
        nr = 0;
        for ( int i = 1; i <= n && nr <= 2; i++ ) {
            if ( c[i] == 1 && nr == 0 )
                x = i, nr++;
            if ( c[i] == 1 )
                y = i;
        }
        for ( int i = x; i <= x + ( y - x ) / 2; i++ ) {
            swap ( b[i], b[y - i + x ] );
        }
        ok = 1;
        for ( int i = 1; i <= n; i++ )
            if ( a[i] != b[i] ) {
                ok = 0;
                break;
            }
        if ( ok == 1 )
            cout << 1 << endl << x << ' ' << y;
        else
            cout << 0;
    }
    return 0;
}

