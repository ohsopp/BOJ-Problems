
// 백준 2751 수 정렬하기 2

#include <iostream>
#include <algorithm>
using namespace std;

int n, a[1000001];

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    
    sort(a, a + n);
    
    for(int i = 0; i < n; i++) cout << a[i] << '\n';
}
