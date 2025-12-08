#include <bits/stdc++.h>

using namespace std;

// 노드 구조체 선언
struct Node {
    char data;
    Node *left;
    Node *right;
};

// N의 최대값에 따라 미리 선언 
Node* tree[26];

// 전위순회
void preorder(Node *cur);
// 중위순회
void inorder(Node *cur);
// 후위순회
void postorder(Node *cur);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 트리 포인터 배열 초기화
    for (int i = 0; i < 26; i++) {
        tree[i] = new Node();
        tree[i]->left = nullptr;
        tree[i]->right = nullptr;
    }

    // N 입력 받기
    int N;
    cin >> N;

    // 부모, 왼쪽 자식, 오른쪽 자식 입력 받기
    while (N--) {
        char p, l, r;
        cin >> p >> l >> r;

        // 인덱스 조정
        int index = p - 'A';

        // 해당 데이터값 추가
        tree[index]->data = p;

        // 포인터 연결
        if (l != '.') tree[index]->left = tree[l - 'A'];
        if (r != '.') tree[index]->right = tree[r - 'A'];
    }

    // 전,중,후위순회 값 출력
    preorder(tree[0]);
    cout << '\n';
    inorder(tree[0]);
    cout << '\n';
    postorder(tree[0]);
    cout << '\n';

    return 0;
}

// 전위순회 (루트, 왼쪽, 오른쪽)
void preorder(Node *cur) {
    if (!cur) return;
    cout << cur->data;
    preorder(cur->left);
    preorder(cur->right);
}

// 중위순회(왼쪽, 루트, 오른쪽)
void inorder(Node *cur) {
    if (!cur) return;
    inorder(cur->left);
    cout << cur->data;
    inorder(cur->right);
}

// 후위순회(왼쪽, 오른쪽, 루트)
void postorder(Node *cur) {
    if (!cur) return;
    postorder(cur->left);
    postorder(cur->right);
    cout << cur->data;
}