#include <bits/stdc++.h>
using namespace std;
ifstream fin( "matrice9.in" );
ofstream fout( "matrice9.out" );
int n, m;
int a[1010][1010];
int lg[1010][1010];
int munte[1010][1010];
int vale[1010][1010];
void vmunte();
void vvale();
void solve( int i );
int si, sj, di, dj, amax;
int s[1010], v;
int main()
{
    fin >> n >> m;

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            {
                fin >> a[i][j];
                munte[i][j] = vale[i][j] = lg[i][j] = 1;
            }

    vmunte();
    vvale();

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            lg[i][j] = max( vale[i][j], munte[i][j] );

    /*for( int i = 1; i <= n; i++ )
         {
             for( int j = 1; j <= m; j++ )
                 fout << lg[i][j] << ' ';

             fout << endl;
         }
    */
    for( int i = 1; i <= m; i++ )
        {
            solve( i );
        }

    //fout << amax << endl;
    fout << si << ' ' << sj << ' ' << di << ' ' << dj;
    return 0;
}
void solve( int j )
{
    v = 1;
    s[v] = 1;

    for( int i = 2; i <= n; i++ )
        {
            v++;
            s[v] = i;

            while( lg[s[v]][j] <= lg[s[v - 1]][j] && v >= 2 )
                {
                    int aria = ( s[v] - s[v - 1] ) * lg[s[v - 1]][j];

                    if( aria > amax )
                        {
                            amax = aria;
                            di = s[v];
                            dj = j;
                            sj = j - lg[s[v - 1]][i];
                            si = s[v - 1];
                        }

                    v--;
                }
        }
}
void vvale()
{
    for( int i = 1; i <= n; i++ )
        {
            int cresc = 0, lg = 1;

            for( int j = 1; j <= m; j++ )
                {
                    vale[i][j] = lg;

                    if( !cresc && a[i][j] < a[i][j + 1] )
                        cresc = 1;
                    else if( cresc && a[i][j] > a[i][j + 1] )
                        {
                            lg = 1;
                            cresc = 0;
                        }

                    lg++;
                }
        }

}
void vmunte()
{

    for( int i = 1; i <= n; i++ )
        {
            int cresc = 1, lg = 1;

            for( int j = 1; j <= m; j++ )
                {
                    munte[i][j] = lg;

                    if( cresc && a[i][j] > a[i][j + 1] )
                        cresc = 0;
                    else if( !cresc && a[i][j] < a[i][j + 1] )
                        {
                            lg = 1;
                            cresc = 1;
                        }

                    lg++;
                }
        }

}
