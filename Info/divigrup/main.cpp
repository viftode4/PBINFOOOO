#include <fstream>
using namespace std;
ifstream fin( "divigrup.in" );
ofstream fout( "divigrup.out" );
int n, v[204], d[204], i, j, aux[204], k, t;
int main()
{
    fin >> n;

    for( i = 1; i <= n; i++ )
        {
            fin >> v[i];
            int nrd = 0;

            for( j = 1; j * j < v[i]; j++ )
                if( v[i] % j == 0 )
                    nrd = nrd + 2;

            if( j * j == v[i] )
                nrd++;

            d[i] = nrd;
        }

    for( i = 1; i < n; i++ )
        for( j = i + 1; j <= n; j++ )
            if( d[i] < d[j] )
                {
                    swap( d[i], d[j] );
                    swap( v[i], v[j] );
                }

    int nrgr = 0;

    for( i = 1; i <= n; i++ )
        if( d[i] != d[i - 1] )
            nrgr++;

    fout << nrgr << endl;;
    k = 0;

    for( i = 1; i <= n; i++ )
        {
            k++;
            aux[k] = v[i];

            if( d[i] != d[i + 1] )
                {
                    fout << k << ' ';

                    for( j = 1; j < k; j++ )
                        for( t = j + 1; t <= k; t++ )
                            if( aux[j] > aux[t] )
                                swap( aux[j], aux[t] );

                    for( j = 1; j <= k; j++ )
                        fout << aux[j] << ' ';

                    fout << endl;
                    k = 0;
                }
        }

    return 0;
}
