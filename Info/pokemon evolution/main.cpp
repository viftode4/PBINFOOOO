#include <iostream>
using namespace std;
int n, m, x, y;
int main() {
    ios_base::sync_with_stdio ( 0 );
    cin.tie ( 0 );
    cin >> n >> m >> x >> y;
    cout << min ( n, ( n * y - m ) / ( x + y ) );
         cout << "Hello world!" << endl;
    return 0;
}
