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
string a, b;
int main()
{
    fast();
    cin >> t;

    while( t-- )
        {
            cin >> a >> b;
            reverse( a.begin(), a.end() );
            reverse( b.begin(), b.end() );
            int pos = 0;

            for( int i = 0; b[i]; i++ )
                if( b[i] == '1' )
                    {
                        pos = i;
                        break;
                    }

            for( int i = pos; a[i]; i++ )
                if( a[i] == '1' )
                    {
                        cout << i - pos << '\n';
                        break;
                    }
        }

    return 0;
}
