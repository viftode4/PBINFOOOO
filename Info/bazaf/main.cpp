#include <fstream>
using namespace std;
ofstream fout ( "bazaf.out" );
ifstream fin ( "bazaf.in" );
int n, f1[200];
long long fact[21];
int main()
{
    fact[1] = 1;
    for ( int i = 2; i <= n; i++ )
        fact[i] = fact[i - 1] * i;
    fin >> cer;
    if ( cer == 1 )
    {

    }
    return 0;
}
