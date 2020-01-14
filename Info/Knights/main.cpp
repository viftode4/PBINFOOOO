#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= n; j++ )
                cout << ( ( i + j ) % 2 == 0 ? "W" : "B" );

            cout << endl;
        }

    return 0;
}
