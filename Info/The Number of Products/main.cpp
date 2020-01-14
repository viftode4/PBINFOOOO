#include <bits/stdc++.h>
using namespace std;
int n, neg, poz, x;
int a[200005], sp[200005];
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a[i];
            x++;

            if( a[i] >= 0 )
                poz++;
            else
                {
                    neg++;
                    x = 0;
                }
        }

    return 0;
}
