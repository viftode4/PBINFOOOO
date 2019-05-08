#include <bits/stdc++.h>
using namespace std;
ifstream fin( "artifact.in" );
ofstream fout( "artifact.out" );
long long n, m, nrsol, nr, cate, sum, coef[40];
int primul[40], use[13];
long long val[13][13];
map<char, long long>ca, cb;
string a, b;
void generarecoef();
void gen( int x, long long sum );
int main()
{
    fin >> n >> m;

    for( int i = 1; i <= n; i++ )
        {
            fin >> a;
            long long len = a.size(), p = 1;

            for( int j = len - 1; j >= 0; j-- )
                {
                    char c = NULL;
                    c = a[j];
                    ca[c] += p;
                    p *= 10;
                }

            int c = a[0] - 'A' + 1;

            if( len > 1 )
                primul[c] = 1;
        }

    for( int i = 1; i <= m; i++ )
        {
            fin >> b;
            long long len = b.size(), p = 1;

            for( int j = len - 1; j >= 0; j-- )
                {
                    char c = NULL;
                    c = b[j];
                    cb[c] += p;
                    p *= 10;
                }

            int c = b[0] - 'A' + 1;

            if( len > 1 )
                primul[c] = 1;
        }

    for( char i = 'A'; i <= 'Z'; i++ )
        {
            int x = i - 'A' + 1;
            coef[x] = ca[i] - cb[i];

            if( coef[x] != 0 )
                cate++;
        }

    generarecoef();
    gen( 1, 0LL );
    fout << nr << '\n';
    return 0;
}
void generarecoef()
{
    int t = cate;

    for( int i = 1; i <= 30; i++ )
        if( coef[i] )
            {
                if( primul[i] )
                    val[cate][0] = -1;

                for( int k = 1; k <= 9; k++ )
                    val[cate][k] = 1LL * coef[i] * k;

                cate--;
            }

    cate = t;
}
void gen( int x, long long sum )
{
    if( x >= cate + 1 )
        {
            if( sum == 0 )
                nr++;

            return;
        }

    for( int i = 0; i <= 9; i++ )
        {
            if( val[x][i] == -1 || use[i] )
                continue;

            use[i] = 1;
            gen( x + 1, sum + val[x][i] );
            use[i] = 0;
        }

    return;
}
