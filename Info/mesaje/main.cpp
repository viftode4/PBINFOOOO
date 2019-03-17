#include <bits/stdc++.h>
using namespace std;
ifstream fin( "mesaje.in" );
ofstream fout( "mesaje.out" );
//cuv baza
char  m[30000];
vector<string>m0;
//rest
char s[130][30000];
map<string, int>cc;
vector<string> v;
int n = 1, k, nr = 1;
bool cond( string& a, string& b )
{
    return cc[a] < cc[b];
}
int main()
{
    fin.getline( m, 30000 );
    char *p;
    p = strtok( m, " " );

    while( p )
        {
            m0.push_back( p );
            p = strtok( NULL, " " );
        }

    while( fin.getline( s[n], 30000 ) )
        n++;


    int skip = 0;

    for( int i = n; i >= 1 && !k; i-- )
        {
            p = strtok( s[i], " " );
            int j = 0;

            while( p )
                {
                    if( p == m0[j] )
                        {
                            cc[p]++;

                            if( cc[p] == 1 )
                                v.push_back( p );

                            nr++;
                            k = 1;
                        }

                    p = strtok( NULL, " " );
                    j++;
                }

            skip = i;
        }

    for( int i = 1; i <= n; i++ )
        {
            if( i == skip )
                continue;

            p = strtok( s[i], " " );

            while( p )
                {
                    cc[p]++;
                    p = strtok( NULL, " " );
                }
        }

    sort( v.begin(), v.end(), cond );

    for( auto it : v )
        fout << cc[it] << ' ';;

    return 0;
}
