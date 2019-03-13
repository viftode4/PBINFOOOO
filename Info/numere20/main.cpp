#include <fstream>
using namespace std;
ifstream fin( "numere20.in" );
ofstream fout( "numere20.out" );
long long n, a, b, x, y, z;
int main() {
    fin >> n >> a >> b;
    x = ( n - 1 ) / a + 1;
    y = ( n - 1 ) / b + 1;
    z = ( n - 1 ) / ( a * b ) + 1;
    fout << n - x - y + z;
    return 0;
}
