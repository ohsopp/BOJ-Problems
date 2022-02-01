
// 백준 14226 이모티콘

#include <iostream>
#include <queue>
using namespace std;

#define MAX 2000
queue<pair<int, int>> q;
queue<int> c;
int s;
bool visit[2000][2000];

int bfs() {
	visit[1][0] = 1;
	q.push({ 1,0 });
	c.push(0);

	while (!q.empty()) {
		int disp = q.front().first, clip = q.front().second;
		int cnt = c.front();
		q.pop(); c.pop();

		if (disp == s) return cnt;

		if (disp > 0 && disp <MAX) {

			// 1. 화면에 있는 이모티콘을 모두 클립보드로 복사하는 연산
			if (!visit[disp][disp]) {
				visit[disp][disp] = 1;
				q.push({ disp, disp });
				c.push(cnt + 1);
			}

			// 3. 화면에 있는 이모티콘 중 하나를 삭제하는 연산
			if (!visit[disp - 1][clip]) {
				visit[disp - 1][clip] = 1;
				q.push({ disp - 1, clip });
				c.push(cnt + 1);
			}
		}

		// 2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣는 연산
		if (clip && disp + clip < MAX) {
			if (!visit[disp + clip][clip]) {
				visit[disp + clip][clip] = 1;
				q.push({ disp + clip,clip });
				c.push(cnt + 1);
			}
		}
	}

	return 0;
}

int main() {
	cin >> s;

	cout << bfs();
}
