#include <bits/stdc++.h>
using namespace std;
ifstream fin("puteri5.in");
ofstream fout("puteri5.out");
int a,b,c, s[6][30], e[7];
void putere(int s[i][30], int e) {

}
int main() {
    fin>>a>>b>>c;
    e[1]=pow(a,b);
    e[2]=pow(a,c);
    e[3]=pow(b,a);
    e[4]=pow(b,c);
    e[5]=pow(c,a);
    e[6]=pow(c,b);
    for(int i=1; i<=6; i++) {
        while(e[i]) {
            s[i][0]++;
            s[i][s[i[0]]]=e[i]%10;
            e[i]/=10;
        }
    }
    return 0;
}
