#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "hashuri.in" );
ofstream fout( "hashuri.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
int has( int x )
{
    return ( x % 151243 + 727 ) % 151243;
}
int n, t, x;
vector<int> a[151243];
int main()
{
    fast();
    fin >> n;

    for( int i = 1; i <= n; i++ )
        {
            fin >> t >> x;
            int h = has( x );

            if( t == 1 )
                a[h].pb( x );
            else if( t == 2 )
                {
                    if( find( a[h].begin(), a[h].end(), x ) != a[h].end() )
                        a[h].erase( find( a[h].begin(), a[h].end(), x ) );
                }
            else if( t == 3 )
                fout << ( ( find( a[h].begin(), a[h].end(), x ) != a[h].end() ) ? 1 : 0 ) << '\n';
        }

    return 0;
}
