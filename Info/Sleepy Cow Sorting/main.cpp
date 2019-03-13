#include <bits/stdc++.h>
using namespace std;
ifstream fin( "sleepy.in" );
ofstream fout( "sleepy.out" );
set <int> s;
set <int>::iterator it;
const int N = 1e5 + 10;
int n, a[N];
void afis()
{
    for( auto it : s )
        cout << it << ' ';

    cout << endl;
}
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        fin >> a[i];

    int nr = 1;

    for( int i = n; i >= 2; i-- )
        if( a[i] < a[i - 1] )
            break;
        else
            {
                nr++;
                s.insert( a[i] );
            }

    s.insert( a[n - nr + 1] );
    fout << n - nr << endl;
    int vs = a[n - nr + 1], st = n - nr + 1, vd = a[n];

    for( int i = 1; i <= n - nr; i++ )
        {
            //fout << vs << ' ' << st << ' ' << vd << endl;;
            //afis();

            if( a[i] < vs )
                {
                    fout << st - 2;
                    st--;
                    vs = a[i];
                    s.insert( vs );
                }
            else if( a[i] > vd )
                {
                    fout << n - 1 ;
                    vd = a[i];
                    st--;
                    s.insert( a[i] );
                }
            else
                {
                    s.insert( a[i] );
                    int nr = 0;
                    // afis();

                    for( it = s.begin(); it != s.end(); it++ )
                        if( a[i] == *it )
                            break;
                        else
                            nr++;

                    st--;
                    // fout << nr << ' ';
                    fout << nr + st - 1;
                }

            if( i == n - nr )
                continue;

            fout << ' ';
        }

    return 0;
}
