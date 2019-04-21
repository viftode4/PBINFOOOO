#include <bits/stdc++.h>
using namespace std;
int n, b, a, x, p, ca;
int main()
{
    cin >> n >> b >> a;
    ca = a;

    for( int i = 1; i <= n; i++ )
        {
            cin >> x;
            p = i;

            if( x == 1 && b > 0 )
                {
                    b--;
                    a++;
                    a = min( ca, a );
                }
            else if( x == 1 && b == 0 )
                a--;
            else if( x == 0 && a > 0 )
                a--;
            else if( x == 0 && a == 0 )
                b--;

            if( a == 0 && b == 0 )
                break;
        }

    cout << p;
    return 0;
}
