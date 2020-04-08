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
int n, k, e, s, sol;
int a[110];
int main()
{
    fast();
    cin >> n >> k;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a[i];

            if( a[i] == 1 )
                e++;
            else
                s++;
        }

    for( int i = 1; i <= n; i++ )
        {
            int ce = 0, cs = 0;

            for( int j = i; j <= n; j += k )
                if( a[j] == 1 )
                    ce++;
                else
                    cs++;


            for( int j = i - k; j > 0; j -= k )
                if( a[j] == 1 )
                    ce++;
                else
                    cs++;

            sol = max( sol, abs( ( e - ce ) - ( s - cs ) ) );
        }

    cout << sol;
    return 0;
}
