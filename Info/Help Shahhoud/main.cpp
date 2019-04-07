#include <bits/stdc++.h>
using namespace std;
int t;
string a, b;
int main()
{
    cin >> t;

    for( int k = 1; k <= t; k++ )
        {
            cin >> a >> b;
            int swaps = 0, n = a.size(), ok = 0;
            int v[100005] = {0};
            int nr[4] = {0};

            for( int i = 0; i < n / 2; i++ )
                {
                    char x1, x2, y1, y2;
                    x1 = a[i];
                    y1 = b[i];
                    x2 = a[n - i - 1];
                    y2 = b[n - i - 1];

                    if( x1 == y1 && x2 == y2 )
                        v[i] = 0;
                    else if( x1 == y2 && x2 == y1 )
                        v[i] = 1;
                    else
                        {
                            cout << -1 << '\n';;
                            ok = 1;
                            break;
                        }
                }

            if( ok == 1 )
                continue;

            if( v[0] == 1 )
                nr[1]++;
            else
                nr[0]++;

            for( int i = 1; i < n / 2; i++ )
                if( v[i] != v[i - 1] )
                    nr[v[i]]++;

            if( nr[0] == 0 )
                cout << 1 << '\n';
            else if( nr[1] == 0 )
                cout << 0 << '\n';
            else
                cout << nr[0] + nr[1] << '\n';
        }

    return 0;
}
