
// 백준 5557 1학년

#include <iostream>
using namespace std;

int n, a[101];
long long dp[101][21];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)  // a[1]부터 시작
        cin >> a[i];

    dp[1][a[1]] = 1;

    for (int i = 2; i < n; i++)
        for (int j = 0; j <= 20; j++)
            if (dp[i - 1][j]) { // 이전 항 계산 결과의 0 ~ 20 중에 계산된 적이 있는 숫자가 있을 때

                if (j + a[i] <=20) // i 번째 항과의 덧셈이 20 이하인 경우
                    dp[i][j + a[i]] += dp[i - 1][j];

                if (j - a[i] >= 0) // i 번째 항과의 뺄셈이 0 이상인 경우
                    dp[i][j - a[i]] += dp[i - 1][j];
            }

    cout << dp[n - 1][a[n]];
}
