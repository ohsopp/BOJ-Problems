
// 백준 1516 게임 개발

#include <iostream>
#include <queue>
using namespace std;

int n, t[501], cnt[501], dp[501];
bool g[501][501];
queue<int> q;

void solution() {

	while (!q.empty()) {
		int k = q.front();
		q.pop();

		for (int i = 1; i <= n; i++)
			if (g[i][k]) {
				g[i][k] = 0;
				cnt[i]--;
				dp[i] = max(dp[i], dp[k] + t[i]);
				if (!cnt[i]) q.push(i);
			}
	}

	for (int i = 1; i <= n; i++)
		cout << dp[i] << '\n';
}

void input() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		scanf("%d", t + i);

		while (1) {
			int a; scanf("%d", &a);
			if (a < 0) break;

			g[i][a] = 1;
			cnt[i]++;
		}

		if (!cnt[i]) {
			q.push(i);
			dp[i] = t[i];
		}
	}
}

int main() {
	input();
	solution();
}
