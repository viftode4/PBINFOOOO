#include <bits/stdc++.h>
using namespace std;
ifstream fin( "turnuri.in" );
ofstream fout( "turnuri.out" );
int n;
int s1[100001], d1[100001];
int s2[100001], d2[100001];
int a[100001];
vector<int>st1, st2, aux;
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        {
            fin >> a[i];
            s1[i] = s2[i] = 0;
            d1[i] = d2[i] = n + 1;
        }

    s1[1] = 0;
    st1.push_back( 1 );
    a[n + 1] = INT_MAX;

    for( int i = 2; i <= n; i++ )
        {
            if( !st1.empty() )
                {
                    int t = st1.back();

                    while( a[i] > a[t] && !st1.empty() )
                        {
                            // s2[t] = max( st2.back(), st1[st1.size() - 2] );

                            /* if( !st2.empty() && st1.size() < 3 )
                                 s2[t] = st2.back();
                             else if( st2.empty() && st1.size() >= 3 )
                                 s2[t] = st1[st1.size() - 3];
                             else if( !st2.empty() && st1.size() >= 3 )
                                 s2[t] = min( st2.back(), st1[st1.size() - 3] );
                            */
                            if( st1.size() >= 3 )
                                s2[t] = st1[st1.size() - 3];

                            d1[t] = i;

                            aux.push_back( t );
                            st1.pop_back();

                            if( !st1.empty() )
                                t = st1.back();
                        }

                    while( !aux.empty() )
                        {
                            int t = aux.back();

                            if( !st2.empty() )
                                {
                                    int x = st2.back();

                                    while( a[x] < a[t] && !st2.empty() )
                                        {
                                            d2[st2.back()] = i;
                                            st2.pop_back();

                                            if( !st2.empty() )
                                                x = st2.back();
                                        }

                                    if( !st2.empty() )
                                        s2[t] = min( s2[t], st2.back() );
                                }

                            st2.push_back( t );
                            aux.pop_back();
                        }
                }

            s1[i] = st1.back();
            st1.push_back( i );
        }

    while( !st1.empty() )
        {
            aux.push_back( st1.back() );
        }

    for( int i = 0; i < st1.size(); i++ )
        fout << st1[i] << ' ';

    fout << endl;

    for( int i = 0; i < st2.size(); i++ )
        fout << st2[i] << ' ';

    fout << endl;

    for( int i = 1; i <= n; i++ )
        {
            fout << s1[i] << ' ';
            fout << d1[i] << ' ';
            fout << s2[i] << ' ';
            fout << d2[i] << '\n';
        }

    return 0;
}
