#include <bits/stdc++.h>
using namespace std;
ifstream fin("credite.in");
ofstream fout("credite.out");
priority_queue <int> q;
vector<int> a[10005];
int m;
int n, t, c, sum, s;
int main() {
    fin>>n;
    for(int i=1; i<=n; i++) {
        fin>>c>>t;
        m=max(m,t);
        a[t].push_back(c);
    }
    for(int i=m; i>=1; i--) {
            q.push(0);
        for(auto j:a[i])
            q.push(j);
        s=q.top();
        q.pop();
        sum=sum+s;
    }
    fout<<sum;
    return 0;
}
