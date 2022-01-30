
// 백준 2206 벽 부수고 이동하기

#include <iostream>
#include <queue>
using namespace std;

int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
int n, m;
bool d[1001][1001], v[2][1001][1001];

int bfs() {
    v[1][1][1] = 1;
    v[0][1][1] = 1;
    queue<pair<int, int>> xy;
    queue<pair<int, int>> count_wall;

    xy.push({ 1,1 });
    count_wall.push({ 1,0 });

    while (!xy.empty()) {
        int x = xy.front().first;
        int y = xy.front().second;
        int count = count_wall.front().first;
        int wall = count_wall.front().second;
        xy.pop(); count_wall.pop();

        if (x == n && y == m) return count;

        for (int i = 0; i < 4; i++) {
            int X = x + dx[i], Y = y + dy[i];

            if (X && Y && X <= n && Y <= m) { // 범위 체크는 공통

                // (1) 벽 부순 적 없으면서 다음 위치가 0일 때
                if (!d[X][Y] && !wall && !v[wall][X][Y]) {
                    v[wall][X][Y] = 1;
                    xy.push({ X,Y });
                    count_wall.push({ count + 1, wall });
                }

                // (2) 벽 부순 적 없지만 다음 위치가 벽이면서 부술 때
                else if (d[X][Y] && !wall && !v[wall + 1][X][Y]) {
                    v[wall + 1][X][Y] = 1;  // (X, Y)의 벽을 부수므로 v[1][X][Y]를 1로 처리
                    xy.push({ X,Y });
                    // 큐에 벽을 부쉈을 때의 값으로 푸쉬
                    count_wall.push({ count + 1, 1 });
                }

                // (3) 벽 부순 적 있으면서 다음 위치가 0일 때
                if (!d[X][Y] && wall && !v[wall][X][Y]) {
                    v[wall][X][Y] = 1;
                    xy.push({ X,Y });
                    count_wall.push({ count + 1, wall });
                }

                // (4) 벽을 부순 적 있으면서, 다음 위치가 벽일 때는 처리하지 않아도 됨
            }
        }
    }
    return -1;  // (n, m)에 도달할 수 없을 때 -1 반환
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%1d", d[i] + j);

    cout << bfs();
}
