#include <bits/stdc++.h>
using namespace std;
ifstream fin( "ciclueuler.in" );
ofstream fout( "ciclueuler.out" );
#define dimensiune 210
///cum declari un graf usor
vector<int>graf[dimensiune];//vector pentru fiecare nod
//(un fel de lista da mai buna si mai usor de folosit)
vector<int>sol;
int use[dimensiune];
int x, y, n, m;
void euler( int x )
{
    ///in nodul x cautam un vecin sa mergem in el
    //daca nu e gol
    if( !graf[x].empty() )
        {
            //luam ultimul vecin adaugat din graf[x]
            // adica .back() si asta asigura comlpexitate O(1) la stergere
            // adica.pop_back() care e ca si cum ai face n--
            int i = graf[x].back();
            graf[x].pop_back();
            // find() e o functie care returneaza iterator la pozitia elementului
            // pe care il cauti in locul in care il cauti
            // se utilieaza asa
            //find( iterator la inceput , iterator la final , elementul pe care il cauti );
            graf[i].erase( find( graf[i].begin(), graf[i].end(), x ) );
            //dupa ne ducem dupa i si continuam
            euler( i );
        }

    //adaugam x la solutie dupa ce am terminat toata treaba cu el
    sol.push_back( x );
}
int main()
{
    fin >> n >> m;

    while( m )
        {
            m--;
            fin >> x >> y;
            graf[x].push_back( y ); //adaugi la x vecini aici y
            graf[y].push_back( x ); //adaugi la y vecinii aici x
            //pt ca e graf neorientat
        }

    //daca un nod are grad impar nu se poate
    for( int i = 1; i <= n; i++ )
        if( graf[i].size() % 2 != 0 )
            {
                fout << -1;
                return 0;
            }

    euler( 1 );

    //.size returneaza cati termeni are
    for( int i = 0; i < sol.size() - 1; i++ )
        fout << sol[i] << ' ';

    return 0;
}
