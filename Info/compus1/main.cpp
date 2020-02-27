#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "compus1.in" );
ofstream fout( "compus1.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
int m, sol;
int mC = 5;
int mI = 3;
int mH = 1;
int main()
{
    fast();
    fin >> m;

    for( int c = ( m - 3 ) / 8; c * 5 <= m; c++ )
        for( int i = 1; 5 * c + i * 3 <= m && i <= 2 * c + 2; i++ )
            {
                int h = m - 5 * c - 3 * i;

                if( 5 * c + 3 * i + h == m && ( 2 * c + 2 - 2 * i - h ) % 2 == 0 && 2 * i + h <= 2 * c + 2 && h > 0 )
                    {
                        sol++;
                        //fout << "C " << c << " I " << i << " H " << h << '\n';
                    }

            }

    fout << sol;

    return 0;
}
