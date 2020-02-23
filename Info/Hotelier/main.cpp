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
priority_queue<int>l, r;
int n;
string s;
int sol[100005];
int main()
{
    fast();
    cin >> n;
    cin >> s;

    for( int i = 0; i < n; i++ )
        {
            if( s[i] == 'L' )
                {
                    for( int j = 1; j <= 10; j++ )
                        if( !sol[j] )
                            {
                                sol[j] = 1;
                                break;
                            }
                }
            else if( s[i] == 'R' )
                {
                    for( int j = 10; j >= 1; j-- )
                        if( !sol[j] )
                            {
                                sol[j] = 1;
                                break;
                            }
                }
            else
                {
                    int x = s[i] - '0' + 1;
                    sol[x] = 0;
                }
        }

    for( int i = 1; i <= 10; i++ )
        cout << sol[i];

    return 0;
}
