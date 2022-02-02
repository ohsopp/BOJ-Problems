
// 백준 10103 주사위 게임

#include <iostream>
using namespace std;

int n, a, b, sa, sb;

int main() {
	cin >> n;

	while (n--) {
		cin >> a >> b;

		if (a > b) {
			sb += a;
		}
		else if (b > a) {
			sa += b;
		}
	}
	cout << 100 - sa << '\n' << 100 - sb;
}
