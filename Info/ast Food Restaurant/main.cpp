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
int main()
{
    fast();
    cin >> t;

    while( t-- )
        {
            int a, b, c, sol = 0;
            cin >> a >> b >> c;
            if(a>b)
                swap(a,b);
            if(b>c)
                swap(b,c);
            if( a )
                {
                    a--;
                    sol++;
                }

            if( b )
                {
                    b--;
                    sol++;
                }

            if( c )
                {
                    c--;
                    sol++;
                }

            if( a && c )
                {
                    a--;
                    c--;
                    sol++;
                }

            if( a && b )
                {
                    a--;
                    b--;
                    sol++;
                }

            if( b && c )
                {
                    b--;
                    c--;
                    sol++;
                }

            if( a && b && c )
                {
                    a--;
                    b--;
                    c--;
                    sol++;
                }

            cout << sol << '\n';
        }

    return 0;
}
