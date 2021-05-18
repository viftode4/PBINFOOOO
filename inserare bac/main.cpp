#include <iostream>

using namespace std;

void inserare ( int n, int&d )
{
    int ok = 0;
    int a[110], k = 0;
    d = 0;

    while ( n != 0 )
        {
            k++;
            a[k] = n % 10;
            n = n / 10;
        }

    for ( int i = k; i > 1; i-- )
        {
            d = d * 10 + a[i];

            if ( a[i] % 2 == a[i - 1] % 2 )
                {
                    d = d * 10 + ( a[i] + a[i - 1] ) / 2;
                    ok = 1;
                }
        }

    d = d * 10 + a[1];

    if ( ok == 0 )
        d = -1;
}
int main()
{
    int d;
    inserare(12311,d);
    cout<<d;
    return 0;
}
