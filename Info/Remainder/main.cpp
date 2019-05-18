#include <bits/stdc++.h>
using namespace std;
int n, x, y, nrop;
string a;
int main()
{
    cin >> n >> x >> y;
    cin >> a;

    for( int i = n - 1; i >= n - x; i-- )
        {
            //cout << a[i] << ' ';

            if( a[i] == '1' )
                nrop++;
        }

    if( a[n - y - 1] == '1' )
        nrop--;
    else
        nrop++;

    cout << nrop;
    return 0;
}
