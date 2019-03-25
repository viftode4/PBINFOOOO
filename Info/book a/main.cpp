#include <bits/stdc++.h>
using namespace std;
int n, ult, zi;
int x;
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> x;
            ult = max( ult, x );

            if( ult == i )
                zi++;
        }

    cout << zi;
    return 0;
}
