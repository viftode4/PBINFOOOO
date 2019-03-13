#include <bits/stdc++.h>
using namespace std;
int n;
long long s, a, b, k;
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {

            cin >> a >> b >> k;
            s = ( a - b ) * ( k / 2 );
            if( k % 2 == 1 )
                s = s + a;
            cout<<s<<endl;
        }

    return 0;
}
