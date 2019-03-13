#include <iostream>
using namespace std;
int v[1010], i, n, ma, ok, j;
int main() {
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>v[i];
    ok=1;
    while(ok==1) {
        ok=0;
        for(i=1; i<=n; i++)
            cout<<v[i]<<' ';
                    cout<<endl;
        for(i=2; i<=n; i++) {
            if(v[i-1]%2==v[i]%2&&v[i]!=v[i-1]) {
                n++;
                for(j=n; j>=i+1; j--)
                    v[j]=v[j-1];
                v[i]=(v[i-1]+v[i])/2;
                ok=1;
                i++;
            }
        }

    }

    return 0;
}
