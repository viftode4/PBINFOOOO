#include <bits/stdc++.h>
using namespace std;
ifstream fin( "taietura.in" );
ofstream fout( "taietura.out" );
long long n, s;
long long a[100005];
long long mars[100006];
map<long long, vector<int>> sume;
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        {
            fin >> a[i];
            s += a[i];
            sume[s].push_back( i );

            if( s == 0 )
                {
                    mars[1]++;
                    mars[i + 1]--;
                }
        }

    for ( auto it : sume )
        {
            vector<int> v = it.second;
            int m = v.size();

            for( int i = 0; i < m - 1; i++ )
                for( int j = i + 1; j < m; j++ )
                    {
                        int x = v[i] + 1;
                        int y = v[j] + 1;
                        mars[x]++;
                        mars[y]--;
                    }
        }

    for( int i = 1; i <= n; i++ )
        {
            mars[i] += mars[i - 1];
            fout << mars[i] << ' ';
        }


    return 0;
}
