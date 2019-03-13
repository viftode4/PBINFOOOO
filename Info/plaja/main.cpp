#include <fstream>
using namespace std;
ifstream fin ( "plaja.in" );
ofstream fout ( "plaja.out" );
int n, k, t;
struct zi
{
    int n, t;
} a[100001];
int maxi;
int main()
{
    fin >> n >> k >> t;
    for ( int i = 1; i <= k; i++ )
    {
        fin >> a[i].n >> a[i].t;
        maxi = max ( a[i].t, maxi );
    }
    for ( int i = 1; i < n; i++ )
    {

    }

    return 0;
}
