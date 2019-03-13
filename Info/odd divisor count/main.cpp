#include <iostream>
#include <cmath>
using namespace std;
int a, b, c, ok;
int main() {
    cin>>a>>b;
    for ( int i = a; i <= b; i++ ) {
        c = sqrt ( i );
        if ( c * c == i )
            ok++;
    }
    cout<<ok;
    return 0;
}
