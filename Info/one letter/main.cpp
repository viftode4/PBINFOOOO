#include <bits/stdc++.h>
using namespace std;
int n;
string s;
multiset <char> a;
multiset <char>::iterator it;
int main() {
    ios_base::sync_with_stdio ( 0 );
    cin.tie ( 0 );
    cin >> n;
    for ( int i = 1; i <= n; i++ ) {
        cin >> s;
        sort ( s.begin(), s.end() );
        a.insert ( s[0] );
    }
    for ( it = a.begin(); it != a.end(); it++ )
        cout << *it;
    return 0;
}
