
// 백준 7579 앱

#include <iostream>
using namespace std;

int N, M, m[101], c[101], dp[101][10001];

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) scanf("%d", m + i);
	for (int i = 1; i <= N; i++) scanf("%d", c + i);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 10000; j++) {
			if (j < c[i])
            	dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + m[i]);
		}
	}

	int t = 1;
	for (; t <= 10000; t++) if (dp[N][t] >= M) break;

	cout << t;
}
