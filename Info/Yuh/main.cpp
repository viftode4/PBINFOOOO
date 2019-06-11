#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
long long l, r, sl, sr, sum;
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        cin >> a[i];

    l = 0;
    r = n + 1;

    while( l < r )
        {
            if( sl <= sr )
                {
                    if( sl == sr )
                        sum = sl;

                    l++;
                    sl += a[l];
                }
            else
                {
                    r--;
                    sr += a[r];
                }
        }

    cout << sum;
    return 0;
}
