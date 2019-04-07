#include <bits/stdc++.h>
using namespace std;
int t;
long long r, R, a1, a2;
int main()
{
    cin >> t;

    for( int i = 1; i <= t; i++ )
        {
            cin >> R >> r;
            a1 = R * R;
            a2 = r * r * 2;

            if( a1 > a2 )
                cout << 1 << '\n';
            else
                cout << 2 << '\n';
        }

    return 0;
}
