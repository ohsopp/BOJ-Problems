
// 백준 2477 참외밭

#include <iostream>
using namespace std;

pair<int, int> ary[6];
int n, maxArea = 1, cur, res;

int main(){
    
    cin >> n;

    for (int i = 0; i < 6; i++){
        cin >> ary[i].first >> ary[i].second;
    }

    for (int i = 0; i < 6; i++){
        cur = ary[i].second * ary[(i + 1) % 6].second;

        if (cur > maxArea){
            maxArea = cur;
            res = maxArea - ary[(i + 3) % 6].second * ary[(i + 4) % 6].second;
        }
    }

    cout << res * n;
}
