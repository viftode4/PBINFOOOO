#include <bits/stdc++.h>
using namespace std;
map<long long, long long> a;
map<long long, long long>::iterator it;
long long n, x, d, poz, y, z;
int main() {

    ios_base::sync_with_stdio ( 0 );
    cin.tie ( 0 );
    cin >> n;
    for ( int i = 1; i <= n; i++ ) {
        cin >> x;
        a[x] = i;
    }
    poz = a.begin()->second;
    for ( it = a.begin(); it != a.end(); it++ ) {

        x = fabs ( poz - ( it->second ) ), y = n - poz + it->second, z = n - it->second + poz;
        d = d + min ( min ( x, y ), z );
        cout << it->first << ' ' << it->second << ' ' << x << ' ' << y << ' ' << z << ' ' << d << endl;
        poz = it->second;
    }
    cout << d;
    return 0;
}
