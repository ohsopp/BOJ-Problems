
// 백준 1991 트리 순회

#include <iostream>
using namespace std;

int n, root = 'A';
char p, c1, c2;

struct Node {
    char left, right;
};

Node ary[26];

void pre(char current) {
    if (current >= 'A' && current <= 'Z') {
        cout << current;
        pre(ary[current - root].left);
        pre(ary[current - root].right);
    }
}

void in(char current) {
    if (current >= 'A' && current <= 'Z') {
        in(ary[current - root].left);
        cout << current;
        in(ary[current - root].right);
    }
}

void post(char current) {
    if (current >= 'A' && current <= 'Z') {
        post(ary[current - root].left);
        post(ary[current - root].right);
        cout << current;
    }
}

int main() {
    cin >> n;

    while (n--) {
        cin >> p >> c1 >> c2;

        ary[p - root].left = c1;
        ary[p - root].right = c2;
    }

    pre(root);  cout << endl;
    in(root);   cout << endl;
    post(root);
}
