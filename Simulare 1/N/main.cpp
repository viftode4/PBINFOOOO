#include <bits/stdc++.h>
#define NMAX (int)(2e5+4)
#define all(x) x.begin(),x.end()
#define rep(i, l, r) for(int i = l; i < r; ++i)
#define rev(i, r, l) for(int i = r - 1; i >= l; --i)
#define ft first
#define sd second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

ll n, mx;
int fr[12], fr2[12];

bool exists ( ll x )
{
    rep ( i, 0, 10 )
    {
        fr2[i] = 0;
    }

    if ( !x )
        ++fr2[0];

    while ( x )
        {
            ++fr2[x % 10];
            x /= 10;
        }

    rep ( i, 0, 10 )
    {
        if ( fr[i] < fr2[i] )
            return 0;
    }
    return 1;
}

int main()
{

    while ( cin >> n )
        {
            if ( n == 0 )
                break;

            ll aux = n;
            memset ( fr, 0, sizeof fr );
            mx = 0;

            while ( aux )
                {
                    ++fr[aux % 10];
                    aux /= 10;
                    mx = mx * 10 + 9;
                }

            cout << "Hidden squares in " << n << '\n';

            for ( ll i = 0; i * i <= mx; ++i )
                {
                    if ( exists ( i ) && exists ( i * i ) )
                        {
                            cout << i << " * " << i << " = " << i*i << '\n';
                        }
                }

            cout << '\n';
        }

    return 0;
}
