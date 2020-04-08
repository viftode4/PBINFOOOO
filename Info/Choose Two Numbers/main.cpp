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
int n, m, a, b, x;
int main()
{
    fast();
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> x;
            a = max( x, a );
        }
cin >> m;
    for( int i = 1; i <= m; i++ )
        {
            cin >> x;
            b = max( x, b );
        }

    cout << a << ' ' << b;
    return 0;
}
