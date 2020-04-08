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
int t, n;
int main()
{
    fast();
    cin >> t;

    while( t-- )
        {
            cin >> n;

            if( n == 1 || n == 0 )
                cout << "-1\n";
            else
                {
                    for( int i = 1; i < n; i++ )
                        cout << 3;

                    cout << 4 << '\n';
                }
        }

    return 0;
}
