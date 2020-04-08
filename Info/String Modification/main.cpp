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
int n, t;
string s;
vector<pair<string, int>>sol;
int main()
{
    fast();
    cin >> t;

    while( t-- )
        {
            cin >> n;
            cin >> s;
            vector<int>pos;
            char mini = s[0];
            sol.clear();

            for( int i = 0; i < n; i++ )
                mini = min( mini, s[i] );

            for( int i = 0;  i < n; i++ )
                if( mini == s[i] )
                    pos.pb( i + 1 );

            string minis = s;
            int kk = 1;

            for( auto k : pos )
                {
                    string cs = s;

                    for( int i = 0; i < n - k + 1; i++ )
                        reverse( cs.begin() + i, cs.begin() + i + k );

                    if( cs < minis )
                        {
                            kk = k;
                            minis = cs;
                        }
                }

            cout << minis << '\n' << kk << '\n';;
        }

    return 0;
}
