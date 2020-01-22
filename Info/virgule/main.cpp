#include <bits/stdc++.h>
using namespace std;
ifstream fin( "virgule.in" );
ofstream fout( "virgule.out" );
string s, sols;
long long virg[1000], nr, pn = 0, un = LLONG_MAX, nrv;
void gen( int i, long long ant )
{
    if( i == s.size() && nrv >= 2 )
        {
            nr++;
            string sol = "";
            long long x = 0, y = 0, p = 1;

            for( int k = 0; s[k]; k++ )
                {
                    sol += s[k];

                    if( virg[k] )
                        sol += ',';
                }

            if( sol.back() == ',' )
                sol.pop_back();

            reverse( sol.begin(), sol.end() );

            for( int k = 0; sol[k]; k++ )
                {
                    if( sol[k] == ',' )
                        break;

                    x = x * 10 + sol[k] - '0';
                }

            for( int k = sol.size() - 1; k >= 0; k-- )
                {
                    if( sol[k] == ',' )
                        break;

                    y += p * ( sol[k] - '0' );
                    p = p * 10;
                }

            //cout << sol << ' ' << y << ' ' << x << '\n';

            if( y < un )
                {
                    pn = x;
                    un = y;
                    sols = sol;
                }
            else if( y == un && pn < x )
                {
                    pn = x;
                    sols = sol;
                }

            return;
        }

    long long p = 1, nr = 0;

    for( int k = i; k <= i + 18 && s[k]; k++ )
        {
            nr += p * ( s[k] - '0' );
            p = p * 10;

            if( nr < ant )
                {
                    virg[k] = 1;
                    nrv++;
                    gen( k + 1, nr );
                    nrv--;
                    virg[k] = 0;
                }
            else
                return;
        }
}
int main()
{
    fin >> s;
    reverse( s.begin(), s.end() );
    gen( 0, LLONG_MAX );
    fout << sols;
    return 0;
}
