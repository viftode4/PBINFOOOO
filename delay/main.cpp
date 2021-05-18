#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
void fast()
{
    cin.tie ( 0 );
    ios_base::sync_with_stdio ( 0 );
}
int n, a[100005], last, d[100005], sol[100005];
int main()
{
    fast();
    cin >> n;
    last = 1;
    sol[1] = a[1];

    for ( int i = 1; i <= n; i++ )
        cin >> a[i];

    for ( int i = 1; i <= n; i++ )
        cin >> d[i];

    sol[1] = a[1];

    for ( int i = 2; i <= n; i++ )
        {
            if ( i - d[i] <= last )
                {
                    sol[i] = a[last];
                }
            else
                {
                    last = i - d[i];
                    sol[i] = a[last];
                }
        }

    for ( int i = 1; i <= n; i++ )
        cout << sol[i] << ' ';

    return 0;
}
