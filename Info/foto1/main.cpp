#include <fstream>
using namespace std;
ifstream fin("foto.in");
ofstream fout("foto.out");
struct {
    int i,  j;
} v[200000], el;
int di[]= {0,-1,0,1,0};
int dj[]= {0,0,1,0,-1};
int n, m, vf, pr,lgmax;
int a[110][110];
int main() {
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            fin>>a[i][j];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            if(a[i][j]==0) {
                vf=1, pr=0;
                v[vf].i=i;
                v[vf].j=j;
                while(pr<=vf) {
                    pr++;
                    el=v[pr];
                    a[el.i][el.j]=1;
                    for(int d=1; d<=4; d++) {
                        if(a[el.i+di[d]][el.j+dj[d]]==0) {
                            vf++;
                            v[vf].i=el.i+di[d];
                            v[vf].j=el.j+dj[d];
                        }
                    }
                }
                if(lgmax<vf)
                    lgmax=vf;
            }
        }
    fout<<lgmax;
    return 0;
}
