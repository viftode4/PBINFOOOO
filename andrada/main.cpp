#include <iostream>
using namespace std;
int n, x, i, s3, s7, s;
int main()
{
    cin >> n;

    for ( i = 1; i <= n; i++ )
        {
            cin >> x;

            if ( x % 3 == 0 )
                s3 = s3 + x;

            if ( x % 7 == 0 )
                s7 = s7 + x;
        }

    s = s3 - s7;

    if ( s < 0 )
        s = s * -1;

    cout << s;
    return 0;
}
