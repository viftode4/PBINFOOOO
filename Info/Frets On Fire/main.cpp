#include <bits/stdc++.h>
using namespace std;
int n;
long long s[100004];
set<long long> dif;
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        cin >> s[i];

    sort( s + 1, s + n + 1 );

    for( int i = 1; i <= n; i++ )
        {
            cout << s[i] << ' ';

            if( i != n )
                dif.insert( s[i + 1] - s[i] );

        }

    cout << endl;

    for( auto it : dif )
        cout << it << ' ';

    return 0;
}
