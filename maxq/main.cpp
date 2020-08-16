#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin ( "maxq.in" );
ofstream fout ( "maxq.in" );
void fast()
{
    cin.tie ( 0 );
    ios_base::sync_with_stdio ( 0 );
}
int n, m;
int a[200005];
int main()

{
    fast();
    fin >> n;

    for ( int i = 1; i <= n; i++ )
        fin >> a[i];

    return 0;
}
