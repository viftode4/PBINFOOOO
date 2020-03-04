#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "heapuri.in" );
ofstream fout( "heapuri.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
int n;
multiset<int>heap;
int ord[200005], k;
int main()
{
    fast();
    fin >> n;

    for( int i = 1; i <= n; i++ )
        {
            int t;
            fin >> t;

            if( t == 3 )
                fout << *heap.begin() << '\n';
            else
                {
                    int x;
                    fin >> x;

                    if( t == 1 )
                        {
                            k++;
                            ord[k] = x;
                            heap.insert( x );
                        }
                    else
                        heap.erase( heap.find( ord[x] ) );
                }
        }

    return 0;
}
