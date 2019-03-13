#include <cstring>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;
ifstream fin ("evip.in");
ofstream fout ("evip.out");
int n,cerinta;
char c[10001];
int cerinta1() {
    int par=0,impar=0,rez=0,anterior=0,nr;
    nr=strlen(c)-1;
    while(nr!=-1) {
        if((c[nr]-'0')%2==0) {
            if(anterior%2==1) {
                rez=rez+impar*par;
                par=0;
                impar=0;
            }
            par++;
        } else {
            impar++;
        }
        anterior=(c[nr]-'0')%10;
        nr--;
    }
    rez+=impar*par;
    return rez;
}
int cerinta2() {
    int dat=cerinta1(),i;
    i=sqrt(dat)+1;
    for(; i>=1; i--)
        if(dat%i==0)
            return int(dat/i) + i;
}
int cerinta3() {
    int par=0,impar=0,rez=0,anterior=0,maxim=0,id,p=1,vf[10]= {0},v[10]= {0},k=0,suma=0,nr,idnr=0;
    long long s;
    nr=strlen(c)-1;
    while(nr!=0) {
        if((c[nr]-'0')%2==0) {
            if(anterior%2==1) {
                if(impar*par>maxim||maxim==0) {
                    maxim=impar*par;
                    id=nr;
                    idnr=impar+par;
                }
                par=0;
                impar=0;
            }
            par++;
        } else {
            impar++;
        }
        anterior=nr%10;
        nr--;
        p=p*10;
    }
    if(impar*par>maxim||maxim==0) {
        maxim=impar*par;
        id=nr;
        idnr=impar+par;
    }
    for(int i=id; i<=id+idnr; i++) {
        vf[c[i]-'0']++;
        if(vf[c[i]-'0']==1)
            v[k++]=c[i]-'0';
        id/=10;
    }
    sort(v,v+k);
    do {
        s=0;
        for(int i=0; i<k; i++)
            s=s*10+v[i];
        suma+=s;
    } while(next_permutation(v,v+k));
    return suma;
}
int main() {
    fin>>cerinta>>c;
    if(cerinta==1)
        fout<<cerinta1();
    else if(cerinta==2)
        fout<<cerinta2();
    else
        fout<<cerinta3();
    return 0;
}
