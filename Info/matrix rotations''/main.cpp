#include <bits/stdc++.h>
using namespace std;
int a[101][101], n, ct;
void r90 ( int a[51][51] ) {
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= n; j++ ) {
            if ( a[i][j] == 0 )
                a[i][j] = a[ n - j + 1][i];
        }
}
int main() {
    ios_base::sync_with_stdio ( 0 );
    cin.tie ( 0 );
    cin >> n;
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= n; j++ )
            cin >> a[i][j];
    r90 ( a );
    r90 ( a );
    r90 ( a );
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= n; j++ )
            cout << a[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
