#include <iostream>
using namespace std;
int n;
struct p {
    int p, i;
} a[101];
int p[101];
int main() {
    cin >> n;
    for ( int i = 1; i <= n; i++ ) {
        cin >> a[i].p;
        a[i].i = i;
    }
    int cn = n;
    while ( n > 1 )
        for ( int i = 1; i < n; i++ ) {
            if ( a[i].p > a[i + 1].p ) {
                p[a[i].i]++;
                for ( int j = i + 1; j <= n; j++ )
                    a[j] = a[j + 1];
                n--;
                i--;
            } else {
                p[a[i + 1].i]++;
                for ( int j = i; j <= n; j++ )
                    a[j] = a[j + 1];
                n--;
                i--;
            }
        }
    for ( int i = 1; i <= cn; i++ )
        cout << p[i] << ' ';
    return 0;
}
