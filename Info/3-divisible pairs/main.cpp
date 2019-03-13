#include <iostream>
using namespace std;
int n, r1, r2, r0, x, nr;
int main() {
    cin >> n;
    for ( int i = 1; i <= n; i++ ) {
        cin >> x;
        if ( x % 3 == 1 )
            r1++;
        else if ( x % 3 == 2 )
            r2++;
        else
            r0++;
    }
    nr = r1*(r1-1) / 2;
    cout << nr<<' ';
    nr = r2 * ( r2 - 1 ) / 2;
    cout << nr<<' ';
    nr = r1 * r2 * r0;
    cout << nr<<' ';
    nr = r0 * ( r0 - 1 ) / 2;
    cout << nr<<' ';
    return 0;
}
