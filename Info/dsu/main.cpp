#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "entries.in" );
ofstream fout( "entries.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
int n, m, nr = 1;
int father[10005];
map <int, int> normal;
int find( int x )
{
    if( father[x] != x )
        father[x] = find( father[x] );

    return father[x];
}
void unite( int a, int b )
{
    int rootA, rootB;
    rootA = find( a );
    rootB = find( b );

    if( rand() % 2 )
        father[rootA] = rootB;
    else
        father[rootB] = rootA;
}
int main()
{
    fast();
    fin >> m;

    for( int i = 1; i <= 10000; i++ )
        father[i] = i;

    for( int i = 1; i <= m; i++ )
        {
            int x, a, b;
            fin >> a >> b >> x;

            if( normal[a] == 0 )
                normal[a] = ++nr;

            if( normal[b] == 0 )
                normal[b] = ++nr;

            if( x == 1 )
                unite( normal[a], normal[b] );
            else
                {
                    int rootA, rootB;
                    rootA = find( normal[a] );
                    rootB = find( normal[b] );

                    if( rootA == rootB )
                        fout << "1\n";
                    else
                        fout << "0\n";
                }
        }

    return 0;
}
