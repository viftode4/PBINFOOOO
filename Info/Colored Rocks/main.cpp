#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int,int>> pos[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) pos[i].push_back({i, i});
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		pos[u].push_back({u, n + i});
		pos[v].push_back({v, n + i});
	}
	for (int i = 1; i <= n; ++i) {
		cout << pos[i].size() << '\n';
		for (auto p : pos[i]) cout << p.first << ' ' << p.second << '\n';
	}
}
