#include <fstream>
using namespace std;
ifstream fin("muzeu.in");
ofstream fout("muzeu.out");
int di[]= {0,-1,0,1,0};
int dj[]= {0,0,1,0,-1};
struct p {
    int i,j;
} q[100000];
int n, a[300][300], l;
char c;
void afisare() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            fout<<a[i][j]<<' ';
        fout<<endl;
    }
}
int main() {
    fin>>n;
    for(int i=0; i<=n+1; i++)
        a[i][0]=a[0][i]=a[n+1][i]=a[i][n+1]=-2;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) {
            fin>>c;
            if(c=='.')
                a[i][j]=-1;
            else if(c=='P') {
                a[i][j]=0;
                q[++l].i=i;
                q[l].j=j;
            } else
                a[i][j]=-2;
        }
    int p=0;
    while(p<=l) {
        p++;
        for(int d=1; d<=4; d++)
            if(a[q[p].i+di[d]][q[p].j+dj[d]]==-1) {
                l++;
                q[l].i=q[p].i+di[d];
                q[l].j=q[p].j+dj[d];
                a[q[p].i+di[d]][q[p].j+dj[d]]=a[q[p].i][q[p].j]+1;
            }
    }
    afisare();
    return 0;
}
