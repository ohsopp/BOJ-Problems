
// 백준 1181 단어 정렬

#include <iostream>
#include <algorithm>
using namespace std;

string ary[20001];
int n;

bool compare_length(string a, string b) {
	if (a.size() < b.size()) return true;
	return false;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> ary[i];

	sort(ary, ary + n, compare_length);		// 먼저 길이 기준으로 정렬

	for (int i = 0, j = 0; i <= n; i++)
		if (ary[i].size() != ary[j].size()) {
			sort(ary + j, ary + i);
			j = i;
		}


	for (int i = 0; i < n; i++) {
		if (ary[i] == ary[i + 1]) continue;
		cout << ary[i] << '\n';
	}
}
