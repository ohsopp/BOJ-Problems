
// 백준 20922 겹치는 건 싫어

#include <iostream>
using namespace std;

int ans, n, k, ary[200001], cnt[100001];

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) scanf("%d", ary + i);

	int start = 1, end = 0;

	while (end < n) {
		end++;
		cnt[ary[end]]++;

		if (cnt[ary[end]] > k)
			while (cnt[ary[end]] > k) {
				cnt[ary[start]]--;
				start++;
			}

		ans = max(ans, end - start + 1);
	}

	cout << ans;
}
