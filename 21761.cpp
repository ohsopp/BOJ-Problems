
// 백준 21761 초직사각형

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef long double ld;

int n, k;
priority_queue<ll> add[4];
ll num[4];

int main() {
	cin >> n >> k;

	for (int i = 0; i < 4; i++)cin >> num[i];

	while (n--) {
		char x; int l;
		cin >> x >> l;
		add[x - 'A'].push(l);
	}

	while (k--) {
		int idx = -1; ld maxi = -1;

		for (int i = 0; i < 4; i++) {
			if (add[i].empty()) continue;
			ld tmp = (ld)add[i].top() / (ld)num[i];
			if (maxi < tmp) { maxi = tmp; idx = i; }
		}

		int ans = add[idx].top();

		num[idx] += ans;
		add[idx].pop();

		cout << (char)(idx + 'A') << " " << ans << '\n';
	}
}
