#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// 트리 및 원소 저장 벡터 선언
vector<ll> tree, v;

// 트리 구성
ll build(int node, int start, int end) {

    if (start == end) return tree[node] = v[start];

    int mid = (start + end) / 2;

    return tree[node] = build(node * 2, start, mid) + build(node * 2 + 1, mid + 1, end);
}

// 값 갱신
ll update(int node, int start, int end, int index, ll diff) {

    if (index < start || index > end) return tree[node];
    if (start == end) return tree[node] += diff;

    int mid = (start + end) / 2;
    return tree[node] = update(node * 2, start, mid, index, diff) + update(node * 2 + 1, mid + 1, end, index, diff);
}

// 질의
ll query(int node, int start, int end, int left, int right) {
    if (right < start || left > end) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 값 입력 받기
    int N, M, K;
    cin >> N >> M >> K;

    // 트리사이즈는 충분히 크게
    tree.resize(N * 4);
    v.resize(N);

    // 원소 입력 받기
    for (int i = 0; i < N; i++) cin >> v[i];

    // 초기 트리 구성
    build(1, 0, N - 1);

    // 질의
    int Q = M + K;
    while (Q--) {
        ll a, b, c;
        cin >> a >> b >> c;

        // a가 1일 때는 값 갱신이 일어남
        if (a == 1) {
            ll diff = c - v[b - 1];
            v[b - 1] = c;
            update(1, 0, N - 1, b - 1, diff);
        }
        // a가 2일 때는 질의가 일어남
        else if (a == 2) {
            cout << query(1, 0, N - 1, b - 1, c - 1) << '\n';
        }
    }

    return 0;
}