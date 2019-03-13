#include <iostream>
using namespace std;
#define fin cin
#define fout cout
int kc=0,kC=0,kn=0, pc=0, pn=0, pC=0;
int valid(char c[200]) {
    for(int i=0; c[i]; i++)
        if(c[i]>='a'&&c[i]<='z') {
            kc++;
            if(pc==0)
                pc=i;
        } else if(c[i]>='A'&&c[i]<='Z') {
            kC++;
            if(pC==0)
                pC=i;
        } else if(c[i]>='0'&&c[i]<='9') {
            kn++;
            if(pn==0)
                pn=i;
        }
    if(kc==0&&kC==0)
        return 2;
    if(kc==0&&kn==0)
        return 3;
    if(kC==0&&kn==0)
        return 4;
    if(kc==0)
        return 5;
    if(kC==0)
        return 6;
    if(kn==0)
        return 7;
    return 1;
}
char c[200];
int i, t, k;
int main() {
    fin>>t;
    for(int i=1; i<=t; i++) {
        fin>>c;
        kc=0,kC=0,kn=0, pc=0, pn=0, pC=0;
        k=valid(c);
        if(k==2) {
            c[pn]='C';
            c[pn+1]='c';
        } else if(k==3) {
            c[pC]='1';
            c[pC+1]='c';
        } else if(k==4) {
            c[pc]='1';
            c[pc+1]='C';
        } else if(k==5) {
            if(kC>=kn)
                c[pC]='c';
            else
                c[pn]='c';

        } else if(k==6) {
            if(kc>=kn)
                c[pc]='C';
            else
                c[pn]='C';

        } else if(k==7) {
            if(kc>kC)
                c[pc]='1';
            else
                c[pC]='1';
        }
        fout<<c<<endl;
    }
    return 0;
}
