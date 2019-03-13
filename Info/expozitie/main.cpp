#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "expozitie.in" );
ofstream fout ( "expozitie.out" );
unsigned long long n, d, k, n1, n2;
int main()
{
    fin >> n >> d >> k;
    //combinari de d luate cate n-d*k;
    unsigned long long n1 = 1, n2 = 1, n3 = 1;

    for ( long long i = 2; i <= d; i++ )
        n1 = n1 * i;

    for ( long long i = 2; i <= n - d * k ; i++ )
        n2 = n2 * i;

    for( long long i = 2; i <= ( d + 1 ) * k - n; i++ )
        n3 = n3 * i;

    fout << n1 << ' ' << n2 << ' ' << n3;
    return 0;
}
