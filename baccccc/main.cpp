#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin ( "bac.txt" );
ofstream fout ( "xxx.in" );
void fast()
{
    cin.tie ( 0 );
    ios_base::sync_with_stdio ( 0 );
}

int main()
{
    fast();
    int a, b, x;
    fin >> a >> b;
    int lg, lgmax;
    lg = lgmax = 2;

    while ( fin >> x )
        {
            if ( x != a && x != b && a != b )
                lg++;
            else
                {
                    lgmax = max ( lgmax, lg );
                    lg = 2;
                }

            a = b;
            b = x;
        }

    cout << lgmax;
    return 0;
}
