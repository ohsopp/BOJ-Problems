
// 백준 2056 작업

#include <iostream>
#include <vector>
using namespace std;

int n, m, ans, arr_time[10001], dp[10001];
vector<int> task[10001];

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr_time[i] >> m;

		while (m--) {
			int pretask;
			cin >> pretask;
			task[i].push_back(pretask);
		}
	}

	dp[1] = arr_time[1];

	for (int i = 2; i <= n; i++) {
		int max_pretask = 0;

		for (auto r : task[i])
			max_pretask = max(max_pretask, dp[r]);

		dp[i] = max_pretask + arr_time[i];

		ans = max(ans, dp[i]);
	}

	cout << ans;
}
