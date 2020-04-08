#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "reply.in" );
ofstream fout( "reply.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
ll p, t, ct, n;
ll a[100005];
ll sp[100005];
int main()
{
    fast();
    fin >> t;
    ct = t;

    while( t-- )
        {
            fin >> n >> p;

            for( int i = 1; i <= n; i++ )
                {
                    fin >> a[i];
                    sp[i] = sp[i - 1] + a[i];
                }

            ll diff = p, l = 1, r = 0, sum = 0, sr = r, sl = l;

            for( int i = 1; i <= n; i++ )
                {
                    sum += a[i];
                    r++;

                    if( sum - p < diff && sum - p > 0 )
                        {
                            sl = l;
                            sr = r;
                            diff = abs( sum - p );
                        }

                    while( abs( sum - p - a[l] ) < abs( sum - p ) )
                        {
                            sum -= a[l];
                            l++;
                        }

                    if( sum - p < diff && sum - p > 0 )
                        {
                            sl = l;
                            sr = r;
                            diff = abs( sum - p );
                        }
                }

            fout << "Case #" << ct - t << ": " << sl - 1 << ' ' << sr - 1 << '\n';
        }

    return 0;
}
