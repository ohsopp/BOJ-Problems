
// 백준 9251 LCS

#include <iostream>

using namespace std;

int a, b, d[1001][1001];
string s1, s2;

int main() {
	cin >> s1 >> s2;

	a = s1.size();
	b = s2.size();

	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++) {
			if (s1[i] == s2[j])
				d[i + 1][j + 1] = d[i][j] + 1;
			else
				d[i + 1][j + 1] = max(d[i][j + 1], d[i + 1][j]);
		}

	cout << d[a][b];
}
