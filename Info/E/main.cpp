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
int main()
{
    int x;
    int n, mod;
    cin >> x;
    n = x / 1000;
    mod = x % 1000;
    int i = n % 2;

    if( i == 0 )
        i += 2;

    int res = 1;

    for( i; i <= n; i += 2 )
        res = ( res * i ) % mod;

    cout << res;
}
