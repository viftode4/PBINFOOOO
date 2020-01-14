#include <bits/stdc++.h>
using namespace std;
ifstream fin( "lant.in" );
ofstream fout( "lant.out" );
char sep[] = ",:;.!?- ";
char *p;
char s[3000];
string a[300];
int pot[300][300];
int k, n, lg[300];
unordered_map<string, int>m;
int f( string a, string b )
{
    int n = a.size();
    int m = b.size();
    int dp[40][40] = {0};

    // costul sa ajung la sufixul de lg i din a si lg j din b
    for( int i = 0; i <= n; i++ )
        dp[i][m] = n - i;

    for( int i = 0; i <= m; i++ )
        dp[n][i] = m - i;

    for( int i = n - 1; i >= 0; i-- )
        for( int j = m - 1; j >= 0; j-- )
            {
                /// FOARTE FRUSTRANT
                int eg = INT_MAX;

                /// MEGA FRUSTRANT
                if( a[i] == b[j] )
                    eg =  dp[i + 1][j + 1];

                /// TREBUIE LUATE CAZURILE ASTEA SEPARAT PENTRU CA AASDJJASB
                /// ADICA DACA SUNT EGALE NU FACI MIN DINTRE EL SI EGALE PT CA POATE
                /// SA RAMANA LA FEL ADICA SA NU FIE BUN SI SA RAMANA SITUATIA IN
                /// CARE NU S A MODIFICAT NIMIC SI DUPA CELELALTE STADII ADICA INSERT SI DELETE
                /// NU MAI AFECTEAZA DACA SUNT MAI INEFICIENTE(CEEA CE E DESTUL DE CLAR)
                /// AMASKMFDKASFNASFNNASKFAKLNF ...
                dp[i][j] = min( {eg, 1 + dp[i + 1][j], 1 + dp[i][j + 1]} );
            }

    //fout << a << ' ' << b << ' ' << dp[0][0] << '\n';
    return dp[0][0] <= k;
}
int main()
{
    fin >> k;
    fin.get();

    while( fin >> s )
        {
            p = strtok( s, sep );

            while( p )
                {

                    string x = "";

                    for( int i = 0; p[i]; i++ )
                        x += p[i];

                    if( !m[x] )
                        a[++n] = x;

                    p = strtok( NULL, sep );
                    m[x]++;
                }
        }

    for( int i = 1; i < n; i++ )
        for( int j = i + 1; j <= n; j++ )
            pot[i][j] = f( a[i], a[j] );

    lg[n] = 1;

    for( int i = n - 1; i >= 1; i-- )
        {
            for( int j = i + 1; j <= n; j++ )
                if( pot[i][j] )
                    lg[i] += lg[j];

            ///ALTA FRUSTRARE
            ///DACA E GOL INSEAMNA CA NU A FACUT PANA
            ///ACUM PARTE DIN NIMIC SI ESTE CAPAT
            ///DECI PORNESTE UN LANT
            if( !lg[i] )
                lg[i] = 1;
        }

    fout << lg[1];
    return 0;
}
