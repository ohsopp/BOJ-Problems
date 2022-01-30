
// 백준 1967 트리의 지름

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree(10001);
vector<vector<int>> cost(10001);
int m, n, dist, point;
bool visit[10001];

void dfs(int here, int length) {
    visit[here] = 1;

    if (dist < length) {
        point = here;
        dist = length;
    }

    for (int i = 0; i < tree[here].size(); i++)
        if(!visit[tree[here][i]])
            dfs(tree[here][i], length + cost[here][i]);
}

int main() {
    cin >> n;

    int a, b, c;

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        
	// 무방향이므로 각각에 간선 추가
        tree[a].push_back(b);
        tree[b].push_back(a);
        
	// 각각에 가중치 추가
        cost[a].push_back(c);
        cost[b].push_back(c);
    }

    dfs(1, 0);
    memset(visit, 0, sizeof(visit));
    dfs(point, 0);

    cout << dist;
}
