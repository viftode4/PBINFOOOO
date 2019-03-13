#include <bits/stdc++.h>
using namespace std;
ifstream fin( "dishes.in" );
ofstream fout( "dishes.out" );
int v;
vector<int> q[100005];
int s=0;
int plasare( int x )
{
    int ok=0;

    return ok;
}
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        {
            fin >> x;

            if( plasare( x ) )
                continue;

            fout << i;
            return 0;
        }

    return 0;
}
