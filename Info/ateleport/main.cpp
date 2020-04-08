#include <bits/stdc++.h>
#define ll long long
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define INF LLONG_MAX-1e10
using namespace std;
ifstream fin ( "ateleport.in" );
ofstream fout ( "ateleport.out" );
int n, m, p, l, k;
vector<pair<int, int>>g[10005];
vector<int>t[10005];
ll dist[10005];
priority_queue<pair<pair<ll, int>, int>>pq;
void reset_dist()
{
    for ( int i = 1; i <= n; i++ )
        dist[i] = INF;
}
void bfs ( int x )
{
    queue<pair<int, int>>q;
    q.push ( mp ( x, 0 ) );
    dist[x] = x;

    while ( !q.empty() )
        {
            auto xd = q.front();
            q.pop();
            int nod = xd.st;
            int lg = xd.nd;

            if ( lg > l )
                continue;

            if ( lg != 0 )
                t[x].pb ( nod );

            if ( lg == l )
                continue;

            for ( auto it : g[nod] )
                if ( dist[it.st] != x )
                    {
                        dist[it.st] = x;
                        q.push ( mp ( it.st, lg + 1 ) );
                    }
        }
}
int main()
{
    fin >> n >> m >> p >> l >> k;

    for ( int i = 1; i <= m; i++ )
        {
            int x, y, c;
            fin >> x >> y >> c;
            g[x].pb ( mp ( y, c ) );
            g[y].pb ( mp ( x, c ) );
        }

    for ( int i = 1; i <= n; i++ )
        bfs ( i );

    reset_dist();
    dist[1] = 0;
    pq.push ( mp ( mp ( 0LL, 0 ), 1 ) );

    while ( !pq.empty() )
        {
            auto x = pq.top();
            pq.pop();
            int nod = x.nd;
            ll d = x.st.st;
            int tp = x.st.nd;

            if ( tp > k || -d > dist[nod] )
                continue;

            for ( auto it : g[nod] )
                if ( dist[nod] + it.nd < dist[it.st] )
                    {
                        dist[it.st] = dist[nod] + it.nd;
                        pq.push ( mp ( mp ( -dist[it.st], tp ), it.st ) );
                    }

            if ( tp == k )
                continue;

            for ( auto it : t[nod] )
                if ( dist[nod] + p < dist[it] )
                    {
                        dist[it] = dist[nod] + p;
                        pq.push ( mp ( mp ( -dist[it], tp + 1 ), it ) );
                    }
        }

    fout << dist[n];
    return 0;
}
