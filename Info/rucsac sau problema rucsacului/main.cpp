#include <fstream>
using namespace std;
ifstream fin("rucsac.in");
ofstream fout("rucsac.out");
int n, g;
int p[5005], w[5005];
int dp[4][10005];
int main() {
    fin>>n>>g;
    for(int i=1; i<=n; i++)
        fin>>w[i]>>p[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=g; j++)
            dp[i%2][j]=max(p[i]+dp[(i-1)%2][j-w[i]],dp[(i-1)%2][j]);
    fout<<dp[0][g];
    return 0;
}
