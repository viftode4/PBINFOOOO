#include <bits/stdc++.h>
using namespace std;
ifstream fin("bacan.in");
ofstream fout("bacan.out");
struct p {
    string s;
    int n;
} a[100003];
int cmp(p a, p b) {
    return a.s<b.s;
}
string s;
int sum, n, nr;
int main() {
    fin>>n;
    for(int i=1; i<=n; i++) {
        getline(fin,a[i].s,'*');
        fin>>a[i].n;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1; i<=n; i++)
        if(a[i].s!=a[i+1].s)
            nr++;
    fout<<nr;
    for(int i=1; i<=n; i++) {
        if(a[i].s!=a[i+1].s) {
            fout<<a[i].s<<"* "<<sum+a[i].n;
            sum=0;
        } else
            sum=sum+a[i].n;
    }
    return 0;
}
