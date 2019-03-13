#include <bits/stdc++.h>
using namespace std;
#define fin cin
#define fout cout
char c[1000000];
int fr[100], nr1, nr2;
int main()
{
    fin.getline ( c, 1e5 );
    for ( int i = 0; c[i]; i++ )
        fr[c[i] - 'a' + 1]++;
    for ( int i = 1; i <= 100; i++ )
    {
        if ( fr[i] == 1 )
            nr1++;
        else if ( fr[i] >= 2 )
            nr2++;
    }
    if ( nr2 < 2 && nr1 < 2 || nr1 == 2 && nr2 < 2  )
        fout << "No";
    else
        fout << "Yes";
    return 0;
}
