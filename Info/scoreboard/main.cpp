#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "test.in" );
ofstream fout( "ceva.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
pair<pair<int, int>, int>a[10000];
int problem[10000][6][6];
int t, n, l, cat;
int main()
{
    fast();
    fin >> t;
    cat = t;

    while( t-- )
        {
            fin >> n >> l;

            for( int x = 1; x <= n; x++ )
                for( int i = 1; i <= 5; i++ )
                    for( int j = 1; j <= 5; j++ )
                        problem[x][i][j] = 0;

            for( int i = 1; i <= n; i++ )
                {
                    a[i].st.st = a[i].st.nd = 0;
                    a[i].nd = i;
                }

            for( int i = 1; i <= l; i++ )
                {
                    int time, team, pid, sid, s;
                    fin >> time >> team >> pid >> sid >> s;

                    if( s == 1 && problem[team][pid][sid] == 0 )
                        {
                            a[team].st.st -= sid * 100;
                            a[team].st.nd += time;
                            problem[team][pid][sid] = 1;
                        }
                }

            sort( a + 1, a + n + 1 );
            fout << "Case #" << cat - t << ": ";

            for( int i = 1; i <= n; i++ )
                fout << a[i].nd << ' ';

            fout << '\n';
        }

    return 0;
}
