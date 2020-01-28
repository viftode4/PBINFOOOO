#include <bits/stdc++.h>
using namespace std;
int n, nr;
int a[100005];
map<int, int>m;
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a[i];
            m[a[i]]++;

            if( m[a[i]] >= 2 )
                nr++;
        }

    if( nr >= 2 )
        cout << "

             return 0;
}
