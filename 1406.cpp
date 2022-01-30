
// 백준 1406 에디터

#include <iostream>
#include <list>

using namespace std;

string s;
int n;

int main() {
	list<char> l;
	list<char>::iterator it = l.begin();

	cin >> s >> n;

	int t = s.size();

	for (int i = 0; i < t; i++) l.push_back(s[i]);

	it = l.end();
	
	while (n--) {
		char c;

		cin >> c;

		if (c == 'L') {
			if (it != l.begin()) it--;
		}
		else if (c == 'D') {
			if (it != l.end()) it++;
		}
		else if (c == 'B') {
			if (it != l.begin()) it = l.erase(--it);
		}
		else if (c == 'P') {
			char x;
			cin >> x;
			l.insert(it, x);
		}
	}

	for (it = l.begin(); it != l.end(); it++)
		cout << *it;

}
