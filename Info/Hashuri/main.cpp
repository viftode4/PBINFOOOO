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
set<int> a[151243];
int main()
{
    fast();
    fin >> n;

    for( int i = 1; i <= n; i++ )
        {
            fin >> t >> x;
            int h = has( x );

            if( t == 1 )
                a[h].insert( x );
            else if( t == 2 )
                {
                    if( a[h].count( x ) )
                        a[h].erase( a[h].find( x ) );
                }
            else if( t == 3 )
                fout << a[h].count( x ) << '\n';
        }

    return 0;
}
