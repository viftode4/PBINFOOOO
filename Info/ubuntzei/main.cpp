#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define INF 2000005
using namespace std;
ifstream fin ( "ubuntzei.in" );
ofstream fout ( "ubuntzei.out" );
int n, m;
int nr_prieteni, prieten[30];
int a[3000][3000];
int dp[1048576][30];
vector<pair<int, int>>g[3000];
int dist[3000];
void dijkstra( int x )
{
    priority_queue<pair<int, int>>pq;

    for( int i = 1; i <= n; i++ )
        dist[i] = INF;

    dist[x] = 0;
    pq.push( mp( 0, x ) );

    while( !pq.empty() )
        {
            auto t = pq.top();
            pq.pop();

            if( -t.st > dist[t.nd] )
                continue;

            for( auto it : g[t.nd] )
                if( dist[t.nd] + it.nd < dist[it.st] )
                    {
                        dist[it.st] = dist[t.nd] + it.nd;
                        pq.push( mp( -dist[it.st], it.st ) );
                    }
        }

    for( int i = 1; i <= n; i++ )
        a[x][i] = dist[i];
}
int main()
{
    fin >> n >> m;
    fin >> nr_prieteni;

    for ( int i = 0; i < nr_prieteni; i++ )
        fin >> prieten[i];

    for ( int i = 1; i <= m; i++ )
        {
            int x, y, z;
            fin >> x >> y >> z;
            g[x].pb ( mp ( y, z ) );
            g[y].pb ( mp ( x, z ) );
        }

    for( int i = 0; i < nr_prieteni; i++ )
        dijkstra( prieten[i] );

    dijkstra( 1 );

    if( nr_prieteni == 0 )
        {
            fout << a[1][n];
            return 0;
        }

    prieten[nr_prieteni] = n;
    nr_prieteni++;

    //dp[i][j]
    //drumul de lungime minima pentru configuratia i care se termina in orasul j
    for( int i = 1; i < ( 1 << nr_prieteni ); i++ )

        //fiecare configuratie prin adunarea in baza 2
        for( int j = 0; ( 1 << j ) <= i; j++ )
            {
                //fiecare bit din configuratie pas cu pas
                //vedem daca s ar putea termina configuratia i in orasul j
                if( i & ( 1 << j ) )
                    {
                        //daca bitul j este in i inseamna ca a trecut prin orasul j
                        if( i == ( 1 << j ) )
                            {
                                //inseamna ca nu a trecut prin niciun alt oras inainte deci este distanta directa de la 1 la j
                                dp[i][j] = a[1][prieten[j]];
                                break;
                                //ne oprim pentru ca este singura varianta
                            }

                        //luam fiecare configuratie fara orasul j in ea adica bitul de pe j se face 0
                        //si verificam fiecare oras care a fost vizitat inainte (restul de 1 din configuratie)

                        dp[i][j] = INF;

                        for( int k = 0; ( 1 << k ) <= i; k++ )
                            if( k != j && ( ( 1 << k )& i ) )
                                //se ia drumul minim din configuratia fara j care se termina in orasul k
                                //orasul k este un oras vizitat de dinainte
                                //si spunem ca s a terminat in el drumul
                                //apoi aduaugam drumul de la k la j pentru a il vizita
                                dp[i][j] = min( dp[i][j], dp[i - ( 1 << j )][k] + a[prieten[k]][prieten[j]] );
                    }
            }

    fout << dp[( 1 << nr_prieteni ) - 1][nr_prieteni - 1];
    return 0;
}
