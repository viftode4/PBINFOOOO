#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "undo.in" );
ofstream fout ( "undo.out" );
int n, a, x, v;
vector <int> fr[200001];
int s[1000010];
void f1( int x );
void f2( int x );
void f3( int x );
int f4( int x );
int main()
{
    fin >> n;

    for ( int i = 1; i <= n; i++ )
        {
            fin >> a >> x;

            if( a == 1 )
                f1( x );
            else if( a == 2 )
                f2( x );
            else if( a == 3 )
                f3( x );
            else if( a == 4 )
                fout << f4( x ) << '\n';

            /* cout << "PASUL" << i << ' ' << a << ' ' << x << "\n";

             for( int i = 1; i <= v; i++ )
                 cout << s[i] << '\n';

             cout << endl;*/
        }

    return 0;
}
void f1( int x )
{
    int i = v + 1;

    while( s[i] > 0 && i <= 1000000 )
        {
            fr[s[i]].pop_back();
            s[i] = 0;
            i++;
        }

    v++;
    s[v] = x;

    if( fr[x].size() == 0 )
        fr[x].push_back( 0 );

    fr[x].push_back( v );
}
void f2( int x )
{
    v -= x;
}
void f3( int x )
{
    v += x;
}
int f4( int x )
{
    if( fr[x].size() == 0 )
        return 0;

    int l, r;
    l = 0;
    r = fr[x].size() - 1;

    while( l < r )
        {
            int mid = ( l +  r + 1 ) / 2;

            if( fr[x][mid] > v )
                r = mid - 1;
            else
                l = mid;
        }

    return l;
}
