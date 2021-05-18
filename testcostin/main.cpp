#include <iostream>
using namespace std;
int s, i;
int main()
{
    cin >> s;

    for ( i = 10; i <= 99; i++ )
        if ( i % 10 + i / 10 == s )
            cout << i << ' ';

    return 0;
}
