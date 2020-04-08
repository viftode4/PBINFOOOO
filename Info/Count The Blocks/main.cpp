#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
#define MOD 998244353
using namespace std;
ifstream fin( "xxx.in" );
ofstream fout( "xxx.in" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
ll n;
ll sum;
ll dp[2][200005];
ll sol[200005];
//10 180 2610 34200
int main()
{
    fast();
    cin >> n;
    sol[n] = 10;
    sol[n - 1] = 180;

    for( int i = n - 2; i >= 1; i-- )

        return 0;
}
