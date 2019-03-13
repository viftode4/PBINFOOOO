#include <fstream>
using namespace std;
ifstream fin("expresie9.in");
ofstream fout("expresie9.out");
long long cerinta, n, xmax;
int a[10000], l, rez[10000] ,m;
string c;
int main() {
    fin>>cerinta>>n;
    l=0;
    for(int i=1; i<=n; i++) {
        fin>>c;
        l=0;
        long long s[2], x=0, l=0;
        char d=' ';
        s[0]=s[1]=0;
        for(int i=0; c[i]; i++) {
            if(c[i]>='a'&&c[i]<='i')
                x=x*10+(c[i]-'a'+1);
            else if(c[i]>='j'&&c[i]<='z')
                x=x*100+(c[i]-'a'+1);
            else if(c[i]=='<') {
                d='<';
                s[l]=s[l]+x;
                l=1;
                if(x>xmax)
                    xmax=x;
                x=0;
            } else if(c[i]=='>') {
                d='>';
                s[l]=s[l]+x;
                x=0;
                if(x>xmax)
                    xmax=x;
                l=1;
            } else if(c[i]=='+') {
                s[l]+=x;
                if(x>xmax)
                    xmax=x;
                x=0;
            }
        }
        s[l]+=x;
        if(x>xmax)
            xmax=x;
        //fout<<s[0]<<d<<s[1]<<endl;
        if(d=='<')
            rez[++m]=(s[0]<s[1]);
        else if(d=='>')
            rez[++m]=(s[0]>s[1]);
        else
            rez[++m]=s[0];
    }
    if(cerinta==1)
        fout<<xmax;
    else
        for(int i=1; i<=m; i++)
            fout<<rez[i]<<'\n';

    return 0;
}
