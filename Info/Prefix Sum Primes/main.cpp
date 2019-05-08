#include <bits/stdc++.h>
using namespace std;
int n;
int nr[3];
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            int x;
            cin >> x;

            nr[x]++;
        }

    if( nr[2] > 0 )
        {
            cout << 2 << ' ';
            nr[2]--;
        }

    if( nr[1] > 0 )
        {
            cout << 1 << ' ';
            nr[1]--;
        }

    while( nr[2] > 0 )
        {
            cout << 2 << ' ';
            nr[2]--;
        }

    while( nr[1] > 0 )
        {
            cout << 1 << ' ';
            nr[1]--;
        }

    return 0;
}
