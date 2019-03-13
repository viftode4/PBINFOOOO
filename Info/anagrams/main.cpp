#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int n, nr;
string s;
map <string, int> a;
map <string, int>::iterator i;
int main() {
    cin >> n;
    for ( int i = 1; i <= n; i++ ) {
        cin >> s;
        sort ( s.begin(), s.end() );
        a[s]++;
        nr = max ( nr, a[s] );
    }

    cout << nr;
    return 0;
}
