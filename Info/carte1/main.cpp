#include <iostream>
using namespace std;
int n, i, a, b, nrc, ok, s, nrp;
int main() {
    cin>>n;
    ok=1;
    nrc=1;
    a=1;
    b=9;
    while(ok) {
        for(i=a; i<=b; i++)
            if(s+nrc<=n) {
                s=s+nrc;
                nrp++;
            } else {
                ok=0;
                break;
            }
        a=a*10;
        b=b*10+9;
        nrc++;
    }
    cout<<nrp;
    return 0;
}
