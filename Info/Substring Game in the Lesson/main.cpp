#include <bits/stdc++.h>
using namespace std;
string a;
int fr[40];
int main()
{
    cin >> a;

    for( int i = 0; a[i]; i++ )
        {
            int exista = 0;

            for( int c = 'a'; c < a[i]; c++ )
                if( fr[c - 'a'] )
                    exista = 1;

            fr[a[i] - 'a']++;

            if( exista )
                cout << "Ann\n";
            else
                cout << "Mike\n";
        }

    return 0;
}
