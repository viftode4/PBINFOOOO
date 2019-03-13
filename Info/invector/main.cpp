#include <bits/stdc++.h>
using namespace std;
ifstream fin("invector.in");
ofstream fout("invector.out");
int n, v[100001];
void ras(int p, int u, int v[100001]) {
    if(p>=u) {
        for(int i=1; i<=n; i++)
            fout<<v[i]<<' ';
        exit(0);
    }
    swap(v[p],v[u]);
    ras(p+1,u-1,v);
}
int main() {
    fin>>n;
    for(int i=1; i<=n; i++)
        fin>>v[i];
    ras(1,n,v);
    return 0;
}
