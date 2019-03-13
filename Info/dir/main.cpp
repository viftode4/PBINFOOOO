#include <bits/stdc++.h>
using namespace std;
ifstream fin( "dir.in" );
ofstream fout( "dir.out" );
vector<string> a, rez;
vector<string>::iterator t;
string r;
char s[10001];
#define sep "\\"
char cuv[10001], v;
int main()
{
    fin.getline( s, 10000 );
    v = -1;

    for( int i = 0; s[i]; i++ )
        {
            if( s[i] == '(' )
                {
                    cuv[v + 1] = NULL;
                    a.push_back( cuv );
                    v = -1;
                    cuv[v + 1] = NULL;
                }
            else if( s[i] == ')' )
                {
                    if( v > -1 )
                        {
                            for( t = a.begin(); t != a.end(); t++ )
                                {
                                    r = r + *t + sep ;
                                }

                            cuv[v + 1] = NULL;
                            r = r + cuv;
                            rez.push_back( r );
                            r = "";
                        }

                    v = -1;
                    cuv[v + 1] = NULL;
                    a.pop_back();
                }
            else if( s[i] == ',' )
                {
                    if( v > -1 )
                        {
                            for( t = a.begin(); t != a.end(); t++ )
                                {
                                    r = r + *t + sep ;
                                }

                            cuv[v + 1] = NULL;
                            r = r + cuv;
                            rez.push_back( r );
                            r = "";
                        }

                    v = -1;
                    cuv[v + 1] = NULL;
                }
            else if( s[i] == ' ' )
                {
                    v = -1;
                    cuv[v + 1] = NULL;
                    continue;
                }
            else
                cuv[++v] = s[i];
        }

    fout << rez.size() << endl;
    //sort( rez.begin(), rez.end() );

    for( t = rez.begin(); t != rez.end(); t++ )
        fout << *t << endl;

    return 0;
}
