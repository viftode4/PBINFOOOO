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
ll n, x, sum, maxim;
int main()
{
    fast();
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> x;
            sum += x;
            maxim = max( maxim, x );
        }

    if( sum % 2 == 0 && sum - maxim >= maxim )
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
