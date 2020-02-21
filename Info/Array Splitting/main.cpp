#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "xxx.in" );
ofstream fout( "xxx.in" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
vector<int> s;
int n, x, y, k, sol;
int main()
{
    fast();
    cin >> n >> k;
    cin >> x;

    for( int i = 2; i <= n; i++ )
        {
            cin >> y;
            s.pb( y - x );
            x = y;
        }

    sort( s.begin(), s.end() );

    for( int i = 0; i < n - k; i++ )
        sol += s[i];

    cout << sol;
    return 0;
}
