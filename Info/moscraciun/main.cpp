#include <fstream>
using namespace std;
ifstream fin("moscraciun.in");
ofstream fout("moscraciun.out");
struct loc {
    int i, j;
} a[1000001];
int di[]= {0,1,0,-1,0};
int dj[]= {0,0,-1,0,1};
int n, m, mi, mj, vf, nr=0;
int v[200][200];
int main() {
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            fin>>v[i][j];
            if(v[i][j]==2)
                mi=i, mj=j;
        }
    vf=1;
    a[vf].i=mi;
    a[vf].j=mj;
    int pr=0;
    while(pr<=vf) {
        pr++;
        if(v[a[pr].i][a[pr].j]==3)
        nr++;
        for(int d=1; d<=4; d++)
            if(v[a[pr].i+di[d]][a[pr].j+dj[d]]>0) {
                    vf++;
                a[vf].i=a[pr].i+di[d];
                a[vf].j=a[pr].j+dj[d];
            }
    }
    fout<<nr;
    return 0;
}
