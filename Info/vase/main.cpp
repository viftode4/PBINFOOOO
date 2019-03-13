#include <bits/stdc++.h>
using namespace std;
#define fin cin
#define fout cout
int v1, v2, c, n;
char r1[100000], r2[100000];
void afisare() {
    fout<<n;
    for(int i=1; i<=n; i++)
        fout<<r1[i]<<' '<<r2[i]<<endl;
}
void generare(int a, int b, int r) {
    if(a==c||b==c) {
        n=r;
        afisare();
        exit(0);
    }
    if(a!=v1) {
        r1[r]='R';
        r2[r]='A';
        generare(v1,b,r+1);
    }
    if(b!=v2) {
        r1[r]='A';
        r2[r]='B';
        generare(min(0,a-(v2-b)),min(v2,b+a), r+1);
    }
    r1[r]='C';
    r2[r]='A';
    generare(0,b,r+1);
    if(b!=v2) {
        r1[r]='R';
        r2[r]='B';
        generare(a,v2,r+1);
    }
    if(a!=v1) {
        r1[r]='B';
        r2[r]='A';
        generare(min(v1,a+b),min(0,b-(v1-a)), r+1);
    }
}
int main() {
    fin>>v1>>v2>>c;
    generare(0,0,1);
    return 0;
}
