#include <iostream>
using namespace std;
struct p
{
    char s, r;
} a, b;
int main()
{
    cin >> a.s >> a.r;

    for( int i = 1; i <= 5; i++ )
        {
            cin >> b.s >> b.r;

            if( b.s == a.s || b.r == a.r )
                {
                    cout << "YES";
                    return 0;
                }
        }

    cout << "NO";
    return 0;
}
