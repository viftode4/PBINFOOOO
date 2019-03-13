#include <iostream>
using namespace std;
const int MOD=998244353;
int n,v[100005], p=1;
int main() {
    cin>>n;

    for(int i=1; i<=n; i++)
        cin>>v[i];
    for(int i=1; i<=n; i++)
        if(v[i]==-1) {
            if(v[i+1]==-1)
                p=p*200%MOD;
            else
                p=p*(max(v[i+1],v[i-1])-min(v[i+1],v[i-1]))%MOD;
        }
    cout<<p;
    return 0;
}
