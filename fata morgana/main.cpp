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
ll n;
ll a[300005];
vector<pair<ll, ll>>sol;
int main()
{
    fast();
    cin >> n;

    for ( int i = 1; i <= n; i++ )
        cin >> a[i];

    sort ( a + 1, a + n + 1 );

    for ( int i = 1; i <= n / 2; i++ )
        {
            ll x = a[i];
            ll y = a[n - i + 1];
            sol.pb ( mp ( x, y ) );
        }

    sort ( sol.begin(), sol.end() );
    auto last = sol.back();
    sol.pop_back();

    for ( auto it : sol )
        cout << it.st << ' ' << it.nd << ' ';

    if ( n % 4 != 0 && sol[0].st != sol[0].nd )
        cout << last.nd << ' ' << last.st;
    else
        cout << last.st << ' ' << last.nd;

    return 0;
}
