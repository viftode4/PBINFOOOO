#include <fstream>
using namespace std;
ifstream fin("alee.in");
ofstream fout("alee.out");
int n, m, x, y, x1, x2, y1, y2, vf, a[200][200], pr;
int dx[5]= {0,-1,0,1,0};
int dy[5]= {0,0,1,0,-1};
struct p {
    int x, y;
} v[100000], el;
int main() {
    fin>>n>>m;
    for(int i=0; i<=n+1; i++)
        a[i][0]=a[0][i]=a[i][n+1]=a[n+1][i]=-1;
    for(int i=1; i<=m; i++) {
        fin>>x>>y;
        a[x][y]=-1;
    }
    fin>>x1>>y1>>x2>>y2;
    vf=1;
    v[vf].x=x1;
    v[vf].y=y1;
    a[x1][y1]=1;
    while(pr<=vf&&a[x2][y2]==0) {
        pr++;
        el=v[pr];
        for(int i=1; i<=4; i++)
            if(a[el.x+dx[i]][el.y+dy[i]]==0) {
                vf++;
                v[vf].x=el.x+dx[i];
                v[vf].y=el.y+dy[i];
                a[el.x+dx[i]][el.y+dy[i]]=a[el.x][el.y]+1;
            }
    }

    fout<<a[x2][y2];
    return 0;
}
