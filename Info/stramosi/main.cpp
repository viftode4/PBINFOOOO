#include <fstream>
using namespace std;
ifstream fin( "stramosi.in" );
ofstream fout( "stramosi.out" );
int n, m, nod, ord, s[250010][20];
int main()
{
    fin >> n >> m;

    for( int i = 1; i <= n; ++i )
        fin >> s[i][0] ;

    for( int k = 1; k <= 16; ++k )
        for( int i = 1; i <= n; i++ )
            s[i][k] = s[s[i][k - 1]][k - 1];

    for( int i = 1; i <= m; i++ )
        {
            fin >> nod >> ord;

            for( int cat = 0; cat <= 16; ++cat )
                if( ord & ( 1 << cat ) )
                    nod = s[nod][cat];

            fout << nod << '\n';
        }

    return 0;
}
