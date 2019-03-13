#include <iostream>
using namespace std;
int v[1001],i,n,j;
int main() {
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>v[i];
    for(i=1; i<=n; i++) {
        int prim=1;
        if(v[i]==0||v[i]==1||v[i]%2==0&&v[i]!=2)
            prim=0;
        for(j=3; j*j<=v[i]; j=j+2) {
            if(v[i]%j==0)
                prim=0;
        }
        if(prim==0)
            cout<<v[i]<<' ';
    }
    return 0;
}
