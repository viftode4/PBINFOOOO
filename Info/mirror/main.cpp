#include <fstream>
using namespace std;
ifstream fin ( "mirror.in" );
ofstream fout ( "mirror.out" );
int n, cerinta, k;
int a[5000001], d[100011];
int main()
{
    fin >> cerinta;
    fin >> n >> k;
    int m = 0, x;

    int b2[100] = {};
    for ( int i = 1; i <= n; i++ )
    {
        fin >> x;
        int t = 0;
        while ( x != 0 )
        {
            b2[++t] = x % 2;
            x = x / 2;
        }
        d[i] = t;
        for ( int j = m + 1; j <= m + 1 + t; j++ )
            a[j] = b2[t + m + 1 - j];
        m = m + t;
    }
    if ( cerinta == 1 )
    {
        int t = 1;
        while ( m >= k )
        {
            int nr = 0;
            for ( int i = t; i <= t + k - 1; i++ )
                if ( a[i] == 1 )
                    nr = nr * 2 + 1;
                else
                    nr = nr * 2;
            fout << nr << ' ';
            m = m - k;
            t = t + k;
        }
    }
    else
    {
        int t = 1;
        int ok = k % 2;
        for ( int v = 1; v <= n; v++ )
        {
            int g = 1, i;
            for ( i = t; i <= t + d[v] - 1  && g <= k; i++ )
            {
                if ( a[i] != a[i + 1] )
                {
                    g++;
                }
                a[i] = 0;
            }
            while ( a[i] == a[i + 1] )
            i++;
            i--;
            if ( ok )
                for ( int j = i  ; j <= t + d[v] - 1; j++ )
                    a[j] = 1 - a[j];
            t = t + d[i];
        }
        t = 0, ok = 1;
        for ( int i = 1; i <= m; i++ )
        {
            fout << a[i] << ' ';
            t++;
            if ( t == d[ok] )
            {
                fout << endl;
                ok++;
                t = 0;
            }
        }
    }
    return 0;
}
