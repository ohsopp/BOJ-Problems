
// 백준 9084 동전

#include <iostream>
using namespace std;

int t, n, m, a[21], dp[10001];

int main() {
	cin >> t;

	while (t--) {
		cin >> n;

		fill(dp, dp +10001, 0);
		dp[0] = 1;

		for (int i = 1; i <= n; i++) cin >> a[i];

		cin >> m;

		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= m; j++)
				if (j >= a[i])
					dp[j] += dp[j - a[i]];

		cout << dp[m] << '\n';
	}
}
