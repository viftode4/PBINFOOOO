#include <iostream>
using namespace std;
int a[305][305], n, m, lg1, lg2, lgmax, ;
int main()
{
    cin >> n >> m;
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            cin >> a[i][j];
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
        {
            if ( a[i][j] == 1 )
            {
                a[i][j] = 0;
                lg1 = 1;
                cout << i << ' ' << j << endl;
                for ( int k = j + 1; k <= m && a[i][k] == 1; k++ )
                {
                    cout << i << ' ' << k << endl;
                    a[i][k] = 0;
                    lg1++;
                    lg2 = 0;
                    ci = i;
                    while ( a[ci + 1][k] == 1 )
                    {

                        a[ci][k] = 0;
                        ci++;
                        lg2++;
                        cout << ci << ' ' << k << endl;
                    }
                    if ( lg1 + lg2 > lgmax )
                        lgmax = lg1 + lg2;
                }
            }
        }
    cout << lgmax;
    return 0;
}
