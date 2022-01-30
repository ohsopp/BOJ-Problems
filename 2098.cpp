
// 백준 2098 외판원 순회

#include <iostream>
using namespace std;

#define INF 100000007

int n, cost[16][16], dp[16][1 << 16];

int func(int current, int start, int visited) {
    if (visited == (1 << n) - 1)
        if (cost[current][start] == 0) return INF;
        else return cost[current][start];

    int& ret = dp[current][visited];

    if (ret) return ret;

    ret = INF;
    for (int next = 0; next < n; next++) {
        if (!cost[current][next] || visited & (1 << next)) continue;
        ret = min(ret, cost[current][next] + func(next, start, visited + (1 << next)));
    }

    return ret;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", cost[i] + j);

    cout << func(0, 0, 1);  //가장 처음 0번을 방문하므로 00...001 = 1을 visited에 넘겨준다.
}
