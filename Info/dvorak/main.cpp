#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("dvorak.in");
ofstream fout("dvorak.out");
int n, q, st, dr;
char s[30], a[1001], r[1001],*p;
int main() {
    fin>>n;
    fin>>s>>a;
    for(int i=1; i<=n; i++) {
        fin>>q;
        if(q==1) {
            fin>>st>>dr;
            for(int j=st-1; j<=dr-1; j++)
                a[j]=s[a[j]-'a'];
        } else {
            fin>>r;
            p=strstr(a,r);
            if(p==NULL)
                fout<<"Nu"<<endl;
            else
                fout<<"Da"<<endl;
        }
    }
    return 0;
}
