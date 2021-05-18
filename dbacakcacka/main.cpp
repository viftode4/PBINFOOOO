#include <cmath>
#include <iostream>
using namespace std;
int a, b, x, s;
int main()
{
    cin >> a >> b;
    s = 0;

    for ( x = a; x <= b; x++ )
        {
            for ( int j = 1; j <= x / 2; j++ )
                if ( x % j == 0 && sqrt ( j ) *sqrt ( j ) == j )
                    s += j;
        }

    cout << s;
    return  0;
}
