#include <fstream>
using namespace std;
ifstream fin ( "fadema.in" );
ofstream fout ( "fadema.out" );
int n, m;
bool a[1001][1001];
int b[1001][1001], s[1001][1001], c[1001];
int main()
{
    fin >> n >> m;
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
        {
            fin >> a[i][j];
            b[i][j] = 1;
        }
    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = m; j >= 2; j-- )
            if ( a[i][j] != a[i][j - 1] )
                b[i][j - 1] = b[i][j] + 1;
    }
    for ( int j = 1; j <= m; j++ )
    {
        c[1] = b[i][j];
        for ( int i = 2; i <= n; i++ )
        {

        }
    }
    return 0;
}
