#include <iostream>
using namespace std;
char c[25001], a[100001];
int nr, vf;
int main() {

    cin.getline ( c, 2500 );
    for ( int i = 0; c[i]; i++ ) {
        if ( c[i] == '(' ) {
            vf++;
            a[vf] = c[i];
        } else {
            if ( a[vf] == '(' )
                vf--;
            else
            }
    }
    return 0;
}
