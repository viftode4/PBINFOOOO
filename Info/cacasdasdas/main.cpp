#include <bits/stdc++.h>
using namespace std;
long long n, nr, mini, maxi;
long long fr[200005];
int main()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( false );

    cin >> n;
    long long x;

    for( int i = 1; i <= n; i++ )
        {
            cin >> x;
            fr[x]++;
        }

    for( int i = 1; i <= n; i++ )
        if( fr[i] )
            {
                mini++;
                i += 2;
            }

    long long lg = 0, sum = 0;

    for( int i = 1; i <= n + 1; i++ )
        {
            if( fr[i] == 0 )
                {
                    if( sum == lg + 1 )
                        {
                            maxi += lg + 1;

                            if( fr[i - lg - 1] != 0 )
                                fr[i]++;

                            fr[i - lg - 1] ++;
                        }
                    else if( sum >= lg + 2 )
                        {
                            maxi += lg + 2;

                            if( fr[i - lg - 1] != 0 )
                                maxi--;

                            fr[i - lg - 1] ++;
                            fr[i]++;
                        }

                    else
                        maxi += lg;

                    lg = sum = 0;
                }
            else
                lg++, sum += fr[i];
        }

    cout << mini << ' ' << maxi;
    return 0;
}
