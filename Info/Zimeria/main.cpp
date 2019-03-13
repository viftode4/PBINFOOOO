#include <bits/stdc++.h>
using namespace std;
ifstream fin( "zimeria.in" );
ofstream fout( "zimeria.out" );
ofstream fout1( "test.out" );
ifstream fin3( "zimeria.out" );
ifstream fin2( "test.in" );
long long n, cer;
unordered_map <char, char> ord;
unordered_map <char, char> org;
string a[400010];
int main()
{
    fin >> cer >> n;
    string comp;
    fin >> comp;
    char c = 'a';

    for( int i = 0; comp[i]; i++ )
        {
            ord[comp[i]] = c + i;
            org[c + i] = comp[i];
        }

    for( int i = 1; i <= n; i++ )
        {
            fin >> a[i];

            for( int j = 0; a[i][j]; j++ )
                a[i][j] = ord[a[i][j]];
        }

    sort( a + 1, a + n + 1 );

    if( cer == 1 )
        {
            long long nr = 1;

            for( int i = 2; i <= n; i++ )
                if( a[i] != a[i - 1] )
                    nr++;

            fout << nr;
        }
    else if( cer == 2 )
        {
            for( int i = 1; i <= n; i++ )
                {
                    for( int j = 0; a[i][j]; j++ )
                        fout << org[a[i][j]] ;

                    fout << '\n';
                }

            for( int i = 1; i <= n; i++ )
                {
                    string a, b;
                    fin2 >> a;
                    fin3 >> b;

                    if( a == b )
                        fout1 << 1 << '\n';
                    else
                        fout1 << 0 << '\n';
                }
        }

    return 0;
}
