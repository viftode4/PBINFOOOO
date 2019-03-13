#include <bits/stdc++.h>
using namespace std;
int n, a, b, S;
bool ok[100005];
struct p
{
    int s, i;
} s[100005], r[100005];
int cond( p a, p b )
{
    return a.s < b.s;
}
int main()
{
    cin >> n >> a >> b;

    for( int i = 1; i <= n; i++ )
        {
            cin >> s[i].s;
            S = S + s[i].s;
            s[i].i = i;
            r[i] = s[i];
        }

    sort( s + 2, s + n + 1, cond );

    if( r[1].s * a / S >= b )
        {
            cout << 0;
            return 0;
        }

    int p = 1;

    for( int i = n; i >= 1; i -- )
        {
            S = S - s[i].s;
            ok[s[i].i] = 1;
            while( ok[p] == 1 )
                p++;

            if( r[p].s * a / S >= b )
                {
                    cout << n - i + 1 << ' ';
                    break;
                }
        }

    return 0;
}
