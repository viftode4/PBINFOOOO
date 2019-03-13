#include <iostream>
using namespace std;
int n, k, a[200001], l, r, x, c;
int main()
{
    cin >> n >> k;
    for ( int i = 1; i <= n; i++ )
        cin >> a[i];
    for ( int t = 1; t <= k; t++ )
    {
        cin >> c >> l >> r;
        if ( c == 3 )
        {
            int nr = 0;
            for ( int i = l; i <= r; i++ )
                nr = max ( nr, a[i] );
            cout << nr << endl;
        }
        else if ( c == 1 )
        {
            cin >> x;
            for ( int i = l; i <= r; i++ )
                a[i] = a[i] | x;
        }
        else if ( c == 2 )
        {
            cin >> x;
            for ( int i = l; i <= r; i++ )
                a[i] = a[i] & x;
        }
    }
    return 0;
}
