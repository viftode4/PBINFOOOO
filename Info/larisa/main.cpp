#include <iostream>
using namespace std;
int a, b, i, n, k;
int main()
{
    cin >> a >> b;
    k = 0;
    i = a;

    while( i < b )
        {
            i++;
            n = i;

            while( n > 0 )
                {
                    if( n % 10 % 2 == 1 )
                        {
                            k++;
                            cout << i % 10 << ' ';
                        }

                    n = n / 10;
                }
        }

    cout << k + 1;
    return 0;
}
