#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "xxx.in" );
ofstream fout( "xxx.in" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
ll calc[100005][3];
int main()
{
    fast();
    int t;
    cin >> t;
    calc[1][1] = 1;
    calc[1][0] = 1;

    for( int i = 2; i <= 100005; i++ )
        {
            calc[i][0] = 1;
            calc[i][1] = calc[i - 1][1] + calc[i - 1][0];
            calc[i][2] = calc[i - 1][1] + calc[i - 1][2];
        }

    while( t-- )
        {
            ll a, b;
            cin >> a >> b;
            string sol = "";
            int ok = 0, ca = a;

            while( b )
                {
                    if( calc[a - 1][2] >= b && !ok )
                        {
                            sol += 'a';
                            a--;
                        }
                    else if( calc[a - 1][2] < b && !ok )
                        {
                            b -= calc[a - 1][2];
                            a--;
                            sol += 'b';
                            ok = 1;
                        }

                    if( calc[a - 1][1] >= b && ok )
                        {
                            sol += 'a';
                            a--;
                        }
                    else if( calc[a - 1][1] < b && ok )
                        {
                            b -= calc[a - 1][1];
                            a--;
                            sol += 'b';
                            ok++;
                            break;
                        }
                }

            while( sol.size() < ca )
                sol += 'a';

            cout << sol << '\n';
        }

    return 0;
}
