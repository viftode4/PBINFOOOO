#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    int q = 1;
    int i=1;
    cin>>n;
    while ( i < n / i )
        {
            if ( n % i == 0 )
                q += i;

            i += 3;
        }

     cout << q;
    return 0;
}
