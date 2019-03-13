#include <bits/stdc++.h>
using namespace std;
long long n, m, s, k, x, h;
//long long a[100003];
vector<int> a;
vector<int>::iterator i, t;
int main()
{
    cin >> n >> m;

    for( int i = 1; i <= n; i++ )
        {
            cin >> x;

            if( x != 0 )
                a.push_back( x );
        }

    sort( a.begin(), a.end() );
    int k = 1;
    t = a.end();
    t--;
    h = *t;
    for( i = a.begin(); i != t; i++ )
        {
            s = s + *i - 1;

            if( *i >= k && k < h )
                k++;

        }

    cout << s + k - 1;
    return 0;
}
