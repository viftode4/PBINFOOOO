#include <iostream>
using namespace std;
int n, x, r1, r2;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x%2==1)
            r1++;
        else r2++;
    }
    cout<<r1*r2;
    return 0;
}
