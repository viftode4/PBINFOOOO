#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;

void fast()
{
    cin.tie ( 0 );
    ios_base::sync_with_stdio ( 0 );
}
int a[505], ca[505], n;
int cat[505];
int main()
{
    fast();
    cin >> n;

    for ( int i = 1; i <= n; i++ )
        {
            cin >> a[i];
            ca[i] = a[i];
        }

    /// primul patern, in jos
    for ( int i = 2; i <= n; i += 2 )
        {
            while ( a[i - 1] < a[i] )
                {
                    cat[i - 1]++;
                    cat[i]--;
                    a[i - 1]++;
                    a[i]--;
                }

            if ( a[i] == a[i - 1] )
                {
                    if ( i != n )
                        {
                            a[i]--;
                            cat[i]--;
                        }
                    else
                        {
                            a[i - 1]++;
                            cat[i - 1]++;
                        }
                }
        }

    for ( int i = 2; i < n; i += 2 )
        {
            if ( a[i] > a[i + 1] )
                {
                    while ( a[i] > a[i + 1] )
                        {
                            a[i]--;
                            cat[i]--;
                            a[i + 1]++;
                            cat[i + 1]++;
                        }
                }
            else if ( a[i] == a[i + 1] )
                {
                    a[i + 1]++;
                    cat[i + 1]++;
                }
        }

    ll costa = 0;

    for ( int i = 1; i <= n; i++ )
        {
            costa += cat[i] * cat[i];
            cat[i] = 0;
            //cout << a[i] << ' ';
            a[i] = ca[i];
        }

    /// acum invers, in sus
    for ( int i = 2; i <= n; i += 2 )
        {
            while ( a[i - 1] > a[i] )
                {
                    cat[i - 1]--;
                    cat[i]++;
                    a[i - 1]--;
                    a[i]++;
                }

            if ( a[i] == a[i - 1] )
                {
                    if ( i != n )
                        {
                            a[i]++;
                            cat[i]++;
                        }
                    else
                        {
                            a[i - 1]--;
                            cat[i - 1]--;
                        }
                }
        }

    for ( int i = 2; i < n; i += 2 )
        {
            if ( a[i] < a[i + 1] )
                {
                    while ( a[i] < a[i + 1] )
                        {
                            a[i]++;
                            cat[i]++;
                            a[i + 1]--;
                            cat[i + 1]--;
                        }
                }
            else if ( a[i] == a[i + 1] )
                {
                    a[i + 1]--;
                    cat[i + 1]--;
                }
        }

    //cout << endl;
    ll costb = 0;

    for ( int i = 1; i <= n; i++ )
        {
            costb += cat[i] * cat[i];
            cat[i] = 0;
            //cout << a[i] << ' ';
            a[i] = ca[i];
        }

    //cout << endl << costa << ' ' << costb << endl;
    cout << min ( costa, costb );
    return 0;
}
