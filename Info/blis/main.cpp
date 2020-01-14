#include <bits/stdc++.h>
using namespace std;
ifstream fin( "blis.in" );
ofstream fout( "blis.out" );
string s;
int n, k;
int main()
{
    fin >> k;
    fin >> s;
    n = s.size();
    int v = 0;
    int mask = ( 1 << k ) - 1, big;

    for( int i = 0; i < min( k, n ); i++ )
        v = ( v << 1 ) + ( s[i] == '1' );

    big = v;

    for( int i = min( k, n ); i < n; i++ )
        {
            v = ( v << 1 ) + ( s[i] == '1' );
            v = v & mask;
            big = max( big, v );
        }

    fout << big << '\n';

    return 0;
}
