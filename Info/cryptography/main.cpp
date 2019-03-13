#include <iostream>
#include <vector>
using namespace std;
#define fin cin
#define fout cout
int x, n, a[300002], sol[150000], lg;
void cat() {
    a[2]=0;
    lg++;
    sol[lg]=2;
    for(int i=4; i<=300000; i+=2)
        a[i]=1;
    for(int i=3; i<=300000; i+=2)
        if(a[i]==0)
            {for(int j=2;j*i<=300000;j++)
                a[i*j]=1;
            lg++;
            sol[lg]=i;
            }
}
int main() {
    fin>>n;
    cat();
    for(int i=1; i<=n; i++) {
        fin>>x;
        fout<<sol[x]<<'\n';
    }
    return 0;
}
