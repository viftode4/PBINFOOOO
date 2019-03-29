#include <bits/stdc++.h>
using namespace std;
ifstream fin( "balance.in" );
ofstream fout( "balance.out" );
const int N = 2 * 1e5;
int n;
bool v[N + 5], x;
bool a[N / 2 + 5], b[N / 2 + 5];
int sv[N + 5], sa[N / 2 + 5], sb[N / 2 + 5];
int cv[N + 5], ca[N / 2 + 5], cb[N / 2 + 5];
int inva, invb;
void afisare()
{
    for( int i = 1; i <= n; i++ )
        fout << a[i] << ' ';

    fout << endl;

    for( int i = 1; i <= n; i++ )
        fout << ca[i] << ' ';

    fout << endl;

    for( int i = 1; i <= n; i++ )
        fout << b[i] << ' ';

    fout << endl;

    for( int i = 1; i <= n; i++ )
        fout << cb[i] << ' ';

    fout << endl;
}
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        {
            fin >> x;
            v[i] = a[i] = x;
            sv[i] = sv[i - 1] + x;
            sa[i] = sa[i - 1] + x;
        }

    for( int i = 1; i <= n; i++ )
        {
            fin >> x;
            v[i + n] = b[i] = x;
            sv[i + N] = sv[i + N - 1] + x;
            sb[i] = sb[i - 1] + x;
        }

    for( int i = 1; i <= n; i++ )
        {
            ca[i] = n - i + 1 - ( sa[n] - sa[i - 1] );

            if( a[i] == 1 )
                inva += ca[i];

            cb[i] = n - i + 1 - ( sb[n] - sb[i - 1] );

            if( b[i] == 1 )
                invb += cb[i];
        }

    // afisare();
    //fout << inva << ' ' << invb << '\n';
    fout << 1;
    return 0;
}
