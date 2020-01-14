#include <bits/stdc++.h>
using namespace std;
int t, x;
long long p[] = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};
int main()
{
    cin >> t;

    while( t-- )
        {
            cin >> x;
            int nr = 0;

            for( int d = 0; d < 9; d++ )
                for( int i = 1; i <= 9; i++ )
                    if( p[d]*i <= x )
                        nr++;

            cout << nr<<'\n';
        }

    return 0;
}
