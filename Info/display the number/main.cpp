#include <bits/stdc++.h>
using namespace std;
int n, t;
int main()
{
    cin >> n;

    while( n-- )
        {
            cin >> t;

            if( t % 2 == 1 )
                {cout << 7;
            t -= 3;}

            while( t )
                {

                    cout << 1;
                    t -= 2;
                }

            cout << '\n';
        }

    return 0;
}
