#include <bits/stdc++.h>
using namespace std;
ifstream fin( "cezar.in" );
ofstream fout( "cezar.out" );
struct nod
{
    int suv, i;
};
bool operator<( const nod& a, const  nod& b )
{
    return b.suv < a.suv;
}
int n, k, x, y;
vector<int>g[10005];
int grad[10005];
int suv[10005];
priority_queue<nod>q;
long long sol;
int main()
{
    fin >> n >> k;

    for( int i = 1; i < n; i++ )
        {
            suv[i] = 1;
            fin >> x >> y;
            g[x].push_back( y );
            g[y].push_back( x );
            grad[x]++;
            grad[y]++;
        }

    suv[n] = 1;

    for( int i = 1; i <= n; i++ )
        if( grad[i] == 1 )
            {
                nod x;
                x.suv = 1;
                x.i = i;
                q.push( x );
            }

    int cat = n - 1 - k;

    while( cat )
        {
            cat--;
            nod t = q.top();
            int x = t.i;
            int s = t.suv;
            q.pop();

            for( auto it : g[x] )
                {
                    grad[it]--;
                    suv[it] += s;

                    if( grad[it] == 1 )
                        {
                            nod y;
                            y.suv = suv[it];
                            y.i = it;
                            q.push( y );
                        }
                }

            sol += s;
        }

    fout << sol;
    return 0;
}
