
 #include <iostream>
using namespace std;
long long m,n,k,l;
int main() {
    cin>>n>>m>>k>>l;
    if(m>n)
        cout<<-1;
    else {
        int i=1;
        while(m*i-k<=l)
            i++;
        if(m*i>n)
            cout<<-1;
        else
            cout<<i;
    }
    return 0;
}
