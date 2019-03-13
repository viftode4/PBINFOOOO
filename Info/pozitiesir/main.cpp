#include <iostream>
using namespace std;
int n, x, a, nr, ok;
int main() {

    cin>>n>>x;
    nr=0;
    ok=0;
    for(int i=1; i<=n; i++) {
        cin>>a;
        if(a>x)
            nr++;
        if(a==x)
            ok=1;
    }
    if(ok)
        cout<<nr+1;
    else
        cout<<-1;
    return 0;
}
