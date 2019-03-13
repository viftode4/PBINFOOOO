#include <bits/stdc++.h>
using namespace std;
ifstream fin( "reteta.in" );
ofstream fout( "reteta.out" );
map<string, int> m;
map<string, int>::iterator t;
char c[1010], *p, *u;
int s;
string ca;
int nr( char *a )
{
    int n = atoi( a );
    return n;
}
int main()
{
    fin.getline( c, 2000 );
    p = strtok( c, " ()" );

    while( p != NULL )
        {
            int a = nr( p );

            if( a == 0 )
                {
                    u = p;
                    p = strtok( NULL, " ()" );
                    int b = nr( p );
                    ca = u;
                    m[ca] += b;
                }
            else
                s = s + a;

            p = strtok( NULL, " ()" );
        }

    fout << s << '\n';

    for( t = m.begin(); t != m.end(); t++ )
        fout << t->first << ' ' << t->second << '\n';

    return 0;
}
