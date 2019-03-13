#include <bits/stdc++.h>
using namespace std;
ifstream fin("padure.in");
ofstream fout("padure.out");
int prim(int x) {
    if(x==1||x%2==0&&x!=2||x==0)
        return 0;
    for(int d=3; d*d<=x; d+=2)
        if(x%d==0)
            return 0;
    return 1;
}
int x, m, n, k, a[110][110], s[100010], ma[103][103];
int i1,i2,jj,j2;
int main() {
    fin>>n>>m>>k;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            fin>>ma[i][j];
            a[i][j]=a[i][j-1]+a[i-1][j]+ma[i][j]-a[i-1][j-1];
        }
    for(int i=1; i<=k; i++) {
        fin>>i1>>jj>>i2>>j2;
        s[i]=a[i2][j2]-a[i1-1][j2]-a[i2][jj-1]+a[i1-1][jj-1];
    }
    sort(s+1,s+k+1);
    for(int i=k; i>=1; i--)
        if(prim(s[i])) {
            fout<<s[i]<<endl;
            return 0;
        }


    return 0;
}
