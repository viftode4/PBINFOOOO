#include <iostream>
using namespace std;
int n, s, d;
int main()
{
    cin >> n;
    d = 1;

    while ( d <= n )
        {
            if ( n % d == 0 ) // verificam daca d este divizor al lui n
                s = s + d;;

            // daca ne intWereseaza doar divizorii impari
            // nu are sens sa ii luam la rand cautam doar din 2 in 2
            d = d + 2;
        }

    cout << s;
    return 0;
}
