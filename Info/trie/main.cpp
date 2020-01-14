#include <bits/stdc++.h>
using namespace std;
ifstream fin( "trie.in" );
ofstream fout( "trie.out" );
#define ch (*s-'a')
int x;
char s[30];
struct trie
{
    trie *nod[30];
    int cnt, nrfii;
    trie()
    {
        cnt = nrfii = 0;
        memset( nod, 0, sizeof( nod ) );
    }
};
trie *t = new trie;
void add( trie *x, char *s )
{
    if( *s == 0 )
        {
            x->cnt++;
            return;
        }

    if( x->nod[ ch ] == 0 )
        {
            x->nod[ ch ] = new trie;
            x->nrfii++;
        }


    add( x->nod[ ch ], s + 1 );
}
int del( trie *x, char *s )
{
    if( *s == 0 )
        x->cnt--;

    else if( del( x->nod[ ch ], s + 1 ) )
        {
            x->nod[ ch ] = 0;
            x->nrfii--;
        }

    if( x->cnt == 0 && x->nrfii == 0 && x != t )
        {
            delete x;
            return 1;
        }

    return 0;
}
int tip1( trie *x, char *s )
{
    if( *s == 0 )
        return x->cnt;

    if( x->nod[ ch ] )
        return tip1( x->nod[ ch ], s + 1 );

    return 0;
}
int pre( trie *x, char *s, int i )
{
    if( *s == 0 || x->nod[ ch ] == 0 )
        return i;

    return ( x->nod[ ch ], s + 1, i + 1 );
}
void caz( int x )
{
    if( x == 0 )
        add( t, s );
    else if( x == 1 )
        del( t, s );
    else if( x == 2 )
        fout << tip1( t, s ) << '\n';
    else
        fout << pre( t, s, 0 ) << '\n';
}
int main()
{
    while( fin >> x )
        {
            fin >> s;
            //fout<<s<<'\n';
            caz( x );
        }

    return 0;
}
