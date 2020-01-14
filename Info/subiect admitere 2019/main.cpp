#include <iostream>
using namespace std;
int main()
{
    int n, x, m, s, y;
    cin >> n;
    x = n % 10;
    m = 1;
    s = 1;

    while( n > 9 )
        {
            n = n / 10;
            y = n % 10;

            if( ( y - x )*m < 0 )
                {
                    if( m > 0 )
                        m = -1;
                    else
                        s = 0;
                }

            x = y;
        }

    cout << s;
    return 0;
}
