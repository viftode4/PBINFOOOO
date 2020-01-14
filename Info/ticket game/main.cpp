#include <bits/stdc++.h>
using namespace std;
int n, sa, sb, nra, nrb, nr;
string s;
int main()
{
    cin >> n >> s;

    for( int i = 0; i < n / 2; i++ )
        {
            if( s[i] == '?' )
                nra++;
            else
                sa += s[i] - '0';
        }

    for( int i = n / 2; i < n; i++ )
        {
            if( s[i] == '?' )
                nrb++;
            else
                sb += s[i] - '0';
        }

    nra /= 2;
    nrb /= 2;
    nr = nra - nrb;

    if( sa + nr * 9 == sb )
        cout << "Bicarp\n";
    else
        cout << "Monocarp\n";

    return 0;
}
