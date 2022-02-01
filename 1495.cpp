
// 백준 1495 기타리스트

#include <iostream>
using namespace std;

int chk, res, N, S, M, a[52];
bool dp[51][1001];

int main() {
	
	cin >> N >> S >> M;

	for (int i = 1; i <= N; i++) cin >> a[i];
	
	dp[0][S] = 1;

	for (int i = 0; i < N; i++)
		for (int j = 0; j <= M; j++)
			if (dp[i][j]) {
				if (j + a[i + 1] <= M) dp[i + 1][j + a[i + 1]] = 1;
				if (j - a[i + 1] >= 0) dp[i + 1][j - a[i + 1]] = 1;
			}
	
	chk = -1;

	for (int i = M; i >= 0; i--)
		if (dp[N][i]) {
			chk = i;
			break;
		}

	cout << chk;
}
