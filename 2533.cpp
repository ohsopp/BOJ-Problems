
// 백준 2533 사회망 서비스(SNS)

#include <iostream>
#include <vector>
using namespace std;

int n, u, v, dp[1000001][2];
bool visit[1000001];
vector<int> tree[1000001];

void dfs(int current) {

	visit[current] = 1;

	for (auto child : tree[current]) {
		if (visit[child]) continue;

		dfs(child);

		dp[current][0] += dp[child][1];
		dp[current][1] += min(dp[child][0], dp[child][1]);
	}

	dp[current][1]++;
}

int main() {

	cin >> n;

	for (int i = 1; i < n; i++) {

		scanf("%d %d", &u, &v);

		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(1);

	cout << min(dp[1][0], dp[1][1]);
}
