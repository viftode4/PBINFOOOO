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
string sol;
int k, n, nr, x;
int fr[100005];
int main()
{
    fast();
    cin >> k >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> x;

            if( fr[x] == 0 )
                nr++;

            fr[x]++;

            if( nr == k )
                {
                    cout << 1;

                    for( int j = 1; j <= k; j++ )
                        {
                            fr[j]--;

                            if( fr[j] == 0 )
                                nr--;
                        }

                    continue;
                }

            cout << 0;
        }

    return 0;
}
