#include <bits/stdc++.h>

using namespace std;

// 트리 및 원본 원소 저장 벡터
vector<int> tree, v;

// 트리 구성
int build(int node, int start, int end) {

    if (start == end) return tree[node] = v[start];

    int mid = (start + end) / 2;

    return tree[node] = min(build(node * 2, start, mid), build(node * 2 + 1, mid + 1, end));
}

// 트리 질의
int query(int node, int start, int end, int left, int right) {

    if (right < start || left > end) return INT_MAX;

    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 원소 개수 및 질의 개수 입력 받기
    int N, M;
    cin >> N >> M;

    // 트리 크기 충분히 크게 하고,
    // 초기화
    tree.resize(N * 4);
    v.resize(N);

    // 원소 입력 받기
    for (int i = 0; i < N; i++) cin >> v[i];

    // 트리 초기구성
    build(1, 0, N - 1);

    // 질의 수행
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        cout << query(1, 0, N - 1, a - 1, b - 1) << '\n';
    }
    return 0;
}