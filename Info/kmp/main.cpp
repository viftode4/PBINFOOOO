#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "strmatch.in" );
ofstream fout( "strmatch.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
vector<int>sol;
string a, b;
int lps[2000005];
void calc_lps( string x )
{
    int len = 0;
    lps[0] = 0;
    int n = x.size(), i = 1;

    for( int i = 1; i < n; i++ )
        {
            while( x[i] != x[len] && len )
                len = lps[len - 1];

            if( x[i] == x[len] )
                len++;

            lps[i] = len;
        }
}
int main()
{
    fast();
    fin >> a >> b;
    calc_lps( a );
    int len = 0;

    for( int i = 0; i < b.size(); i++ )
        {
            while( a[len] != b[i] && len )
                len = lps[len - 1];

            if( a[len] == b[i] )
                len++;

            if( len == a.size() )
                {
                    len = lps[a.size() - 1];
                    sol.pb( i - a.size() + 1 );
                }
        }

    fout << min( 1000, ( int )( sol.size() ) ) << '\n';

    for( int i = 0; i < min( 1000, ( int )( sol.size() ) ); i++ )
        fout << sol[i] << ' ';

    return 0;
}
