#include <iostream>
using namespace std;
int n, m, fr[27];
int frcuv[10002][27];
string alfabet, a[10002];
int main()
{
    cin >> m;

    for( int i = 1; i <= n; i++ )
        alfabet += ( 'a' + i - 1 );

    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a[i];

            for( int j = 0; a[i][j]; j++ )
                {
                    frcuv[i][a[i][j] - 'a' + 1]++;
                    fr[a[i][j] - 'a' + 1]++;
                }
        }

    for( int i = 1; i <= m; i++ )
        if( fr[i] == 0 )
            {
                cout << "NU";
                return 0;
            }

    for( int i = 1; i < n; i++ )
        for( int j = i + 1; j <= n; j++ )
            {
                int lcomun = 0;

                for( int t = 1; t <= 26; t++ )
                    lcomun += min( frcuv[i][t], frcuv[j][t] );

                if( lcomun != 1 )
                    {
                        cout << "NU";
                        return 0;
                    }
            }

    cout << "YES";


    return 0;
}
