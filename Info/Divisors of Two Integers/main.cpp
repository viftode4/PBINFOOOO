#include <bits/stdc++.h>
using namespace std;
int n, x, nr1, nr2;
int d[100000];
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> x;
            d[x]++;
            nr1 = max( x, nr1 );
        }

    d[nr1]--;

    for( int i = nr1; i >= 1; i-- )
        if( i == nr1 && d[nr1] == 1 )
            {
                nr2 = nr1;
                break;
            }
        else if( d[i] == 1 && nr1 % i != 0 || d[i] == 2 && nr1 % i == 0 )
            {
                nr2 = i;
                break;
            }
        else if( i == 1 )
            {
                nr2 = 1;
                break;
            }

    cout << nr1 << ' ' << nr2;
    return 0;
}
