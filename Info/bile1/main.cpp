#include <fstream>
using namespace std;
ifstream fin( "bile1.in" );
ofstream fout( "bile1.out" );
long long n, x;
int main() {
    fin >> n;
    x = 1;

    for( int i = 1; i < n; i++ )
        x *= 2;

    x *= 3;
    fout<<x;
    return 0;
}
