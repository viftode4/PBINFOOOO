#include <bits/stdc++.h>
using namespace std;
int n, k, t;
int main()
{
    cin >> t;

    while( t-- )
        {
            cin >> n >> k;
            int ok = 1;

            if( k % 3 == 0 )
                {
                    int p = n % ( k + 1 );

                    if( p % 3 == 0 && p != k )
                        ok = 0;
                }
            else
                {

                    int p = n % 3;

                    if( p == 0 )
                        ok = 0;
                }

            if( ok == 0 )
                cout << "Bob\n";
            else
                cout << "Alice\n";
        }

    return 0;
}
