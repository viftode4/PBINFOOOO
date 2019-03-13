#include <bits/stdc++.h>
using namespace std;
ifstream fin( "interesant.in" );
ofstream fout( "interesant.out" );
string s[210];
int n, cer;
int cond( string a, string b )
{
    if( a.size() > b.size() )
        return 1;
    else if( a.size() == b.size() )
        for( int i = 0; a[i] && b[i]; i++ )
            if( a[i] < b[i] )
                return 1;

    return 0;
}
int subs( string s, string sol )
{
    int i = 0,  j = 0;
    int n = s.size(), m = sol.size();

    while( i < n && j < m )
        {
            if( s[i] == sol[j] )
                i++;
            else
                j++;
        }

    if( i == n )
        return 1;
    else
        return 0;
}
int main()
{
    fin >> cer >> n;

    for( int i = 1; i <= n; i++ )
        fin >> s[i];

    sort( s + 1, s + n + 1, cond );

    if( cer == 1 )
        fout << s[1];
    else
        {
            string sol[210];
            sol[1] = s[1];
            int v = 1;

            for( int i = 2; i <= n; i++ )
                {
                    int ok = 0;

                    for( int j = 1; j <= v; j++ )
                        if( subs( s[i], sol[j] ) )
                            {
                                ok = 1;
                                break;
                            }

                    if( ok == 0 )
                        {
                            v++;
                            sol[v] = s[i];
                        }
                }

            fout << v << '\n';

            for( int i = 1; i <= v; i++ )
                fout << sol[i] << '\n';
        }

    return 0;
}
