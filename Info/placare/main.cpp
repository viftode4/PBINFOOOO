#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "placare.in" );
ofstream fout ( "placare.out" );
int n, m, x;
int a[311][311];
char c[10001], *p, b[10001];
int main()
{
    fin >> n >> m;
    fin.get();
    for ( int i = 1; i <= n; i++ )
    {
        fout << i << ' ';
        fin.get ( c, 1000 );
        p = strtok ( c, " " );
        string s ( p );
        fout << s;
        while ( p )
        {
            p = strtok ( NULL, " " );
            fout << p << ' ';
        }

    }
    return 0;
}
