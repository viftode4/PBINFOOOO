#include <fstream>
#include <cstring>
using namespace std;
ifstream fin ( "placaj.in" );
ofstream fout ( "placaj.out" );
int n, m;
int a[301][301];
char c[1001], *p;
int main()
{
    fin >> n >> m;
    fin.get();
    for ( int i = 1; i <= n; i++ )
    {
        fin.getline ( c, 1000 );
        p = strtok ( c, " " );
        while ( p != NULL )
        {
            fout << p << ' ';
            p = strtok ( NULL, " " );
        }
        fout << endl;
    }
    return 0;
}
