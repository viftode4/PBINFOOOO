#include <iostream>
using namespace std;
int n, x, y, s;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        s=max(s,x+y);
    }
    cout<<s;
    return 0;
}
