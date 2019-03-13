#include <bits/stdc++.h>
using namespace std;
ifstream fin( "guess.in" );
ofstream fout( "guess.out" );
struct a
{
    map<string, int> m;
    string s[110];
    int n;
} a[110];
int n, nrmax, nr;
string s;
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        {
            fin >> s;
            fin >> a[i].n;

            for( int j = 1; j <= a[i].n; j++ )
                {
                    fin >> a[i].s[j];
                    a[i].m[a[i].s[j]] = 1;
                }
        }

    /*for( int i = 1; i <= n; i++ )
        {
            fout << i << ' ';
            fout << a[i].n;
            fout << endl;

            for( int j = 1; j <= a[i].n; j++ )
                fout << a[i].s[j] << ' ';

            fout << endl;
        }*/

    for( int i = 1; i < n; i++ )
        {
            for( int j = i + 1; j <= n; j++ )
                {
                    nr = 0;
                    /*fout << i << ' ' << j << endl;

                    for( int t = 1; t <= a[j].n; t++ )
                        fout << a[j].s[t] << ' ';

                    fout << endl;

                    for( int t = 1; t <= a[i].n; t++ )
                        fout << a[i].s[t] << ' ';
                    */


                    for( int t = 1; t <= a[i].n; t++ )
                        if( a[j].m[a[i].s[t]] == 1 )
                            nr++;

                    /*fout << nr;
                    fout << endl;
                    fout << endl;*/
                    nrmax = max( nr, nrmax );
                }
        }

    fout << nrmax + 1;
    return 0;
}
