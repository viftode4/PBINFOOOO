#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "ciur.in" );
ofstream fout( "ciur.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
int nr, n;
int prim[2000005];
int main()
{
    fast();
    fin >> n;
    prim[1] = prim[0] = 1;

    for( int i = 2; i <= n; i++ )
        if( !prim[i] )
            {
                nr++;

                for( int j = 2 * i; j <= n; j += i )
                    prim[j] = 1;
            }

    fout << nr;
    return 0;
}
