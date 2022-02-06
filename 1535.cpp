
// 백준 1535 안녕

#include <iostream>
using namespace std;

int n, l[21], k[21], dp[21][101];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)cin >> l[i];
    for (int i = 1; i <= n; i++)cin >> k[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j < 100; j++) {
            if (j < l[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - l[i]] + k[i]);
        }

    cout << dp[n][99];
}
