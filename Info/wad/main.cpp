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
int n, st, dr;
int a[200005];
int main()
{
    fast();
    cin >> n;
    a[0] = INT_MAX;
    a[n + 1] = INT_MAX;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a[i];

            if( a[i] == n )
                {
                    st = i - 1;
                    dr = i + 1;
                }
        }

    int ant = n;
    int ok = 1;

    while( ok )
        {
            ok = 0;

            if( ant - a[st] == 1 )
                {
                    ant = a[st];
                    st--;
                    ok = 1;
                }

            if( ant - a[dr] == 1 )
                {
                    ant = a[dr];
                    dr++;
                    ok = 1;
                }
        }

    if( st == 0 && dr == n + 1 )
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
