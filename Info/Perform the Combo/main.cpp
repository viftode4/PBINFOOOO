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
int t, n, m;
string s;
int a[200005];
int main()
{
    fast();
    cin >> t;

    while( t-- )
        {
            cin >> n >> m;
            cin >> s;
            map<char, int>fr;

            for( auto it : s )
                fr[it]++;

            for( int i = 1; i <= n; i++ )
                a[i] = 0;

            a[0] = m;

            for( int i = 1; i <= m; i++ )
                {
                    int x;
                    cin >> x;
                    x--;
                    a[x + 1]--;
                }

            for( int i = 0; i < n; i++ )
                a[i] += a[i - 1];

            for( int i = 0; i < n; i++ )
                fr[s[i]] += a[i];

            for( char i = 'a'; i <= 'z'; i++ )
                cout << fr[i] << ' ';

            cout << '\n';
        }

    return 0;
}
