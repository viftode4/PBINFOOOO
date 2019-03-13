#include <bits/stdc++.h>
using namespace std;

ifstream fin( "diferenta.in" );
ofstream fout( "diferenta.out" );

int n, m, x, k;
int main() {
    fin >> n >> m;

    for( int i = 1; i <= n; i++ ) {
        for( int j = 1; j <= m; j++ ) {
            fin >> x;
            k = 0;

            for( int d = 1; d * d <= x; d++ )
                if( ( d + x / d )%2 == 0 && x % d == 0 )
                    k++;

            fout << k << ' ';
        }

        fout << endl;
    }

    return 0;
}
