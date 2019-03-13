#include <fstream>
using namespace std;
ifstream fin( "submultimi.in" );
ofstream fout( "submultimi.out" );
int a[30], p;
int n;
void afisare()
{
    for( int i = 1; i <= p; i++ )
        fout << a[i] << ' ';

    fout << '\n';
}
void generare( int k )
{
    for( int i = k + 1; i <= n; i++ )
        {
            p++;
            a[p] = i;
            afisare();
            generare( i );
            p--;
        }
}
int main()
{
    fin >> n;
    generare( 0 );
    return 0;
}
