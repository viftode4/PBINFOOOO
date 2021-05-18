#include <iostream>

using namespace std;

int n, x, m, p, k, i, c;
int main()
{
    cin >> n;
    p = 1;
    m = 0;
    k = 0;

    while ( n != 0 )
        {
            cin >> x;

            for ( i = 1; i <= k; i++ )
                x = x / 10;

            if ( x != 0 )
                c = x % 10;
            else
                c = n % 10;

            m = c * p + m;
            n = n / 10;
            p = p * 10;
            k++;
            cout<<m<<endl;
        }
    cout<<m;

    return 0;
}
