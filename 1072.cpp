
// 백준 1072 게임

#include <iostream>
using namespace std;

long long x, y, z, tmpz, s, mid, e;

int main() {
	cin >> x >> y;

	z = y * 100 / x;

	if (z >= 99) { cout << -1; return 0; }

	s = 0;
	e = 1000000000;

	while (s <= e) {
		mid = (s + e) / 2;

		tmpz = 100 * (y + mid) / (x + mid);

		if (z < tmpz)
			e = mid - 1;
		else
			s = mid + 1;
	}

	cout << s;
}
