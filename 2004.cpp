
// 백준 2004 조합 0의 개수

#include<iostream>
using namespace std;

long long int n, m, i, a, b;

int main() {
	cin >> n >> m;

	m = m < n - m ? m : n - m;

	for (i = 5; i <= n; i *= 5)
		a += n / i - (n - m) / i - m / i;

	for (i = 2; i <= n; i *= 2)
		b += n / i - (n - m) / i - m / i;

	cout << min(a, b);
}
