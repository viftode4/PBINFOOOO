#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "showroom.in" );
ofstream fout ( "showroom.out" );
const int MOD = 9001;
map<string, int> m;
vector<string>v[510];
vector<int> l[510];
char c[100010];
char *p;
string s;
int d[510];
long long f[610];
int num[610];
int n, a, r, k, nr;
int dealer = 1;
long long sum;
void rez( int i )
{
    if( d[i] == 0 )
        {
            d[i] = dealer;
            // cout << i << endl;

            for( auto it : v[i] )
                {
                    // cout << it << endl;

                    for( auto j : l[m[it]] )
                        {
                            //cout << j << endl;
                            rez( j );
                        }
                }
        }
}
long long fact( int x )
{
    long long p = 1;

    if( x == 0 || x == 1 )
        return 1;

    while( x )
        {
            p = p * x;
            x--;
        }

    return p ;
}
int main()
{
    fin >> n >> a >> r >> k;
    fin.get();
    f[1] = a;

    for ( int i = 2; i <= n; i++ )
        f[i] = ( f[i - 1] + r ) % k;

    nr = 1;

    for ( int i = 1; i <= n; i++ )
        {
            fin.getline ( c, 10000 );
            // fout << c << '\n';
            p = strtok ( c, " " );

            while ( p != NULL )
                {
                    s = p;
                    //fout << s << ' ';
                    v[i].push_back ( s );

                    if ( m[s] == 0 )
                        {
                            m[s] = nr;
                            nr++;
                        }

                    l[m[s]].push_back( i );
                    p = strtok ( NULL, " " );
                }
        }

    for( int i = 1; i <= n; i++ )
        {
            if( d[i] == 0 )
                {
                    rez( i );
                    dealer++;
                }
        }

    for( map<string, int>::iterator it = m.begin(); it != m.end(); it++ )
        num[d[l[it->second].back()]]++;

    sum = 1;
    fout << dealer - 1 << endl;

    for( int i = 1; i < dealer; i++ )
        {
            //combinari de num[i] luate cate f[i];
            if( f[i] > num[i] || f[i] == 0 )
                continue;

            long long s = 0, j, n, k;
            n = num[i];
            k = f[i];
            s =  fact( n ) ;
            j = ( fact( k ) * fact( n - k ) );
            cout << s << ' ' << j << endl;
            sum = ( sum * s / j ) % MOD  ;
        }

    fout << sum;
    return 0;
}
