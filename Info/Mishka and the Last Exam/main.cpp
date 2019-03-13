#include <bits/stdc++.h>
using namespace std;
const int NMAX = 2 * 1e5 + 10;
int n;
long long v[NMAX];
long long x;
int main()
{
    cin >> n;

    // 0 0 a b c d
    // 0 1 2 3 4 5
    for( int i = 2; i <= n; i += 2 )
        {
            cin >> x;
            v[i] = v[i - 2];
            v[i + 1] = x - v[i];

            if( v[i + 1] > v[i - 1] && i != 2 )
                {
                    v[i] = v[i] + v[i + 1] - v[i - 1];
                    v[i + 1] = v[i - 1];
                }

            //cout << v[i] << ' ' << v[i + 1] << ' ';
        }

    /* for( int i = 2; i <= n + 1; i ++ )
         cout << v[i] << ' ';



*/
    for( int i = 2; i <= n + 1; i += 2 )
        cout << v[i] << ' ';

    for( int i = n + 1; i >= 2; i -= 2 )
        cout << v[i] << ' ';

    return 0;
}
