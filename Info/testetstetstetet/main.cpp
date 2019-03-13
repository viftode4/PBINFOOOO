#include <iostream>
using namespace std;
int x, s = 0;
int main()
{
    while ( cin >> x )
    {
        if ( x == 0 )
            break;
        else if ( x > 9 )
        {
            if ( x < 100 )
                s = s + x;
            else
            {
                while ( x / 100 >= 1 )
                    x = x / 10;
                s = s + x;
            }
        }
    }
    cout << s;
    return 0;
}
