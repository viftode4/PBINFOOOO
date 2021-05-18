#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin ( "xxx.in" );
ofstream fout ( "xxx.in" );
void fast()
{
    cin.tie ( 0 );
    ios_base::sync_with_stdio ( 0 );
}
ll a[100005], n, fr[100005], frmin = INT_MAX, frmax = 0, rez;
int main()
{
    fast();
    cin >> n;

    for ( int i = 1; i <= n; i++ )
        {
            cin >> a[i];
            fr[a[i]]++;
            frmax = max ( fr[a[i]], frmax );
        }

    for ( int i = 1; i <= n; i++ )
        if ( fr[i] != 0 )
            frmin = min ( fr[i], frmin );

    rez = max ( rez, frmin * frmax );
    cout << rez;
    return 0;
}
