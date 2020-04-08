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
int n;
string a;
int main()
{
    fast();
    cin >> t;

    while( t-- )
        {
            cin >> n;
            cin >> a;
            string sola = "", solb = "";
            int c = n + 1;

            for( int i = 0; i < n; i++ )
                if( a[i] == '2' )
                    {
                        sola += '1';
                        solb += '1';
                    }
                else if( a[i] == '0' )
                    {
                        sola += '0';
                        solb += '0';
                    }
                else
                    {
                        c = i + 1;
                        sola += '1';
                        solb += '0';
                        break;
                    }


            for( int i = c; i < n; i++ )
                if( a[i] == '1' )
                    {
                        solb += '1';
                        sola += '0';
                    }
                else if( a[i] == '2' )
                    {
                        solb += '2';
                        sola += '0';
                    }
                else
                    {
                        solb += '0';
                        sola += '0';
                    }

            cout << sola << '\n' << solb << '\n';
        }

    return 0;
}
