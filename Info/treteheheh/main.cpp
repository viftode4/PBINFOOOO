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

int t;
int a, b, c;
int main()
{
    fast();

    cin >> t;

    while( t-- )
        {
            cin >> a >> b >> c;
            cout << ( a + b + c ) / 2 << '\n';
        }

    return 0;
}
