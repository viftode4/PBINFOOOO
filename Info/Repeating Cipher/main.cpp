#include <bits/stdc++.h>
using namespace std;
int n, p, k;
char c;
int main()
{
    p = 1;
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> c;
            k++;

            if( k == p )
                {
                    p++;
                    k = 0;
                    cout << c;
                }
        }

    return 0;
}
