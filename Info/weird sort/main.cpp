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
int a[105], p[105];
int main()
{
    fast();
    cin>>t;
    while( t-- )
        {
            cin >> n >> m;

            for( int i = 1; i <= n; i++ )
                cin >> a[i];

            for( int i = 1; i <= m; i++ )
                cin >> p[i];

            int ok = 0;

            do
                {
                    ok = 0;

                    for( int i = 1; i <= m; i++ )
                        if( a[p[i]] > a[p[i] + 1] )
                            {
                                ok = 1;
                                swap( a[p[i]], a[p[i] + 1] );
                            }
                }
            while( ok );

            ok = 1;

            for( int i = 1; i < n; i++ )
                if( a[i] > a[i + 1] )
                    {
                        ok = 0;
                        break;
                    }

            if( !ok )
                cout << "NO\n";
            else
                cout << "YES\n";
        }

    return 0;
}
