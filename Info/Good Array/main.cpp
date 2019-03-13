#include <bits/stdc++.h>
using namespace std;
long long n, s;
struct p
{
    long long i, v;
} a[200010];
int cond( p a, p b )
{
    return a.v < b.v;
}
vector<int> v;
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a[i].v;
            a[i].i = i;
            s = s + a[i].v;
        }

    sort( a + 1, a + n + 1, cond );

    for( int i = 1; i <= n; i++ )
        {
            s = s - a[i].v;

            if( i == n )
                {
                    if( a[n - 1].v == s - a[n - 1].v )
                        v.push_back( a[i].i );
                }
            else
                {
                    if( a[n].v == s - a[n].v )
                        v.push_back( a[i].i );
                }

            s = s + a[i].v;
        }

    cout << v.size() << endl;

    for( auto it : v )
        cout << it << ' ';

    return 0;
}
