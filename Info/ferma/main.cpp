#include <bits/stdc++.h>
using namespace std;
ifstream fin( "ferma.in" );
ofstream fout( "ferma.out" );
int n, m, cer, aria, nr, amax;
struct insula
{
    int n;
    char c;
} s[1600010];
char c[410][410], v;
int a[410][410];
int di[] = {0, 1, 0, -1, 0};
int dj[] = {0, 0, -1, 0, 1};
int in( int i, int j )
{
    if( i > n || i < 1 || j < 1 || j > m )
        return 0;

    return 1;
}
void afis()
{
    for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= m; j++ )
                cout << a[i][j] << ' ';

            cout << endl;
        }
}
void fil( int i, int j )
{
    aria++;
    a[i][j] = nr;

    for( int d = 1; d <= 4; d++ )
        if( in( i + di[d], j + dj[d] ) && v == c[i + di[d]][j + dj[d]] && a[i + di[d]][j + dj[d]] == 0 )
            fil( i + di[d], j + dj[d] );
}
int main()
{
    cin >> cer;
    cin >> n >> m;

    for( int i = 1; i <= n; i ++ )
        for( int j = 1; j <= m; j++ )
            cin >> c[i][j];

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            if( a[i][j] == 0 )
                {
                    nr++;
                    //cout<<nr<<endl;
                    aria = 0;
                    v = c[i][j];
                    fil( i, j );
                    s[nr].n = aria;
                    amax = max( amax, aria );
                    s[nr].c = v;
                    // afis();
                    // cout << endl;
                }

    if( cer == 1 )
        cout << amax;


    return 0;
}
