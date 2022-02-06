
// 백준 10826 피보나치 수 4

#include <iostream>
using namespace std;

int n;
string fib[10001] = { "0","1" };

string fib_sum(string a, string b) {

	string res;

	int alen = a.size(),
		blen = b.size(),
		pos = 0,
		carry = 0,
		sum;

	for (; pos < alen && pos < blen; pos++) {
		sum = (a[pos] - '0') + (b[pos] - '0') + carry;

		res += sum % 10 + '0';	// 1의 자리 숫자를 문자로 변환하여 반환 문자열에 추가

		carry = sum / 10;
	}

	while (pos < alen) {
		sum = (a[pos] - '0') + carry;
		res += sum % 10 + '0';
		carry = sum / 10;
		pos++;
	}

	while (pos < blen) {
		sum = (b[pos] - '0') + carry;
		res += sum % 10 + '0';
		carry = sum / 10;
		pos++;
	}

	if (carry) res += carry + '0';	// 마지막 올림수가 있는 경우 문자열에 추가

	return res;
}

int main() {
	cin >> n;

	for (int i = 2; i <= n; i++)
		fib[i] = fib_sum(fib[i - 1], fib[i - 2]);

	for (int i = fib[n].size() - 1; i >= 0; i--)
		cout << fib[n][i];
}
