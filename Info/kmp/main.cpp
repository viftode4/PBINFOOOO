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
//
//    for( auto it : a )
//        fout << it << ' ';
//
//    fout << endl;
//
//    for( int i = 0 ; i < a.size(); i++ )
//        fout << lps[i] << ' ';
//
//    fout << endl;
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

                    if( sol.size() < 1000 )
                        sol.pb( i - a.size() + 1 );
                }
        }

    fout << sol.size() << '\n';

    for( auto it : sol )
        fout << it << ' ';

    return 0;
}
