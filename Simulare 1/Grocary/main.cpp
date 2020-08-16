#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin ( "xxx.in" );
ofstream fout ( "xxx.in" );
void fast()
{
    cin.tie ( 0 );
    ios_base::sync_with_stdio ( 0 );
}

int main()
{
    fast();
    int n;
    cin >> n;
    int t;
    int total = n;

    while ( n-- )
        {
            cin >> t;
            int x;
            ll sum = 0;
            int p, q;

            while ( t-- )
                {
                    cin >> x;

                    if ( x == 1 )
                        {
                            cin >> p >> q;
                            sum += p * q;
                        }
                    else if ( x == 2 )
                        {
                            cin >> p;
                            sum += p;
                        }
                    else
                        {
                            cin.get ( );
                            cin.get ( );
                            cin >> p;
                            sum -= p;
                        }
                }

            cout << "Day " << total - n << ": " << sum << " dollars." << '\n';
        }

    return 0;
}
