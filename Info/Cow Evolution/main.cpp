#include <bits/stdc++.h>
using namespace std;
ifstream fin( "evolution.in" );
ofstream fout( "evolution.out" );
map<string, set<int>>m;
string s;
int n, x;
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        {
            fin >> x;

            for( int j = x; j >= 1; j-- )
                {
                    fin >> s;
                    m[s].insert( i );
                }
        }

    for( auto it : m )
        {
            set<int> s;
            s = it.second;
            cout << it.first << ' ';

            for( auto k : s )
                cout << k << ' ';

            cout << endl;

            if( s.size() == n )
                {
                    fout << "no";
                    return 0;
                }
        }

    fout << "yes";
    return 0;
}
