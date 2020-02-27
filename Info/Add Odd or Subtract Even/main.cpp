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
int t, a, b;
int main()
{
    fast();
    cin >> t;

    for( int i = 1; i <= t; i++ )
        {
            cin >> a >> b;

            if( a == b )
                cout << 0 << '\n';
            else if( a > b )
                {
                    if( a % 2 != b % 2 )
                        cout << 2 << '\n';
                    else
                        cout << 1 << '\n';
                }
            else if( a < b )
                {
                    if( a % 2 != b % 2 )
                        cout << 1 << '\n';
                    else
                        cout << 2 << '\n';
                }
        }

    return 0;
}
