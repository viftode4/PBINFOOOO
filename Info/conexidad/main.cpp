#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define nd second
#define st first
using namespace std;
ifstream fin( "conexidad.in" );
ofstream fout( "conexidad.out" );
vector<int>g[110];
vector<int>nr1, nrextra, aux;
vector< pair<int, int> >sol;
int extra[110];
int use[110], nr;
int cat[110];
int n, m;
int x, y;
void dfs( int x )
{
    use[x] = 1;
    aux.pb( x );

    for( auto it : g[x] )
        if( !use[it] )
            dfs( it );
}
int main()
{
    fin >> n >> m;

    for( int i = 1; i <= n; i++ )
        {
            fin >> x >> y;
            g[x].pb( y );
            g[y].pb( x );
        }

    int last = 0;

    for( int i = 1; i <= n; i++ )
        if( !use[i] )
            {
                aux.clear();
                //pun nodurile din grupa intr un vector aux
                //sa ma ajute sa le retin
                //si sa fac ce vreau cu ele
                dfs( i );

                if( aux.size() == 1 )
                    nr1.pb( i );
                else
                    {
                        //daca e prima grupa pun primul nod in extra
                        if( !last )
                            nrextra.pb( aux[0] );
                        else
                            {
                                sol.pb( mp( last, aux[0] ) );
                                extra[last] = 1;
                                extra[aux[0]] = 1;
                            }

                        last = aux[1];

                        //al doilea oricare ar fi devine anteriorul de care leg urmatoarea grupa mare
                        //de la al treilea pana la final le bag in extra
                        for( int j = 2; j < aux.size(); j++ )
                            nrextra.pb( aux[j] );
                    }
            }

    //ultimul anterior nu il leg de nimic deci il bag in extra
    nrextra.pb( last );

    //nr de noduri de 1 > nr noduri "goale"
    if( nr1.size() > nrextra.size() )
        {
            // le leg lant pe nodurile 1
            for( int i = 1; i < nr1.size(); i++ )
                {
                    sol.pb( mp( nr1[i], nr1[i - 1] ) );
                    extra[nr1[i]]++;
                    extra[nr1[i - 1]]++;
                }

            int x = nrextra.back();
            sol.pb( mp( x, nr1.back() ) );
            extra[x]++;
            extra[nr1.back()]++;
        }
    else
        {
            //le leg la cate un nod gol
            for( int i = 0; i < nr1.size(); i++ )
                {
                    sol.pb( mp( nr1[i], nrextra[i] ) );
                    extra[nrextra[i]]++;
                    extra[nr1[i]]++;
                }
        }

    int maxe = 0;

    for( int i = 1; i <= n; i++ )
        maxe = max( maxe, extra[i] );

    fout << maxe << '\n' << sol.size() << '\n';

    for( auto it : sol )
        fout << it.st << ' ' << it.nd << '\n';

    return 0;
}
