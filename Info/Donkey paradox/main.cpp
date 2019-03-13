#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int n, m, a1, b1, a2, b2, nr;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> a1 >> b1 >> a2 >> b2;
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ ) {
            if ( fabs ( i - a1 ) + fabs ( j - b1 ) == fabs ( i - a2 ) + fabs ( j - b2 ) )
                nr++;
        }
    cout << nr;
    return 0;
}
