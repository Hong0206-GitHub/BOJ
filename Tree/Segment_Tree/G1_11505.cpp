#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

vector<ll> tree, v;

// 세그먼트 트리에 대한
// 구성, 갱신, 질의 함수
ll build(int node, int start, int end);
ll update(int node, int start, int end, int index, ll diff);
ll query(int node, int start, int end, int left, int right);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 원소 개수 및 질의 개수 입력 받기
    int N, M, K;
    cin >> N >> M >> K;

    // 트리 및 원소 저장 벡터 사이즈 재정의
    tree.resize(N * 4);
    v.resize(N);

    // 원소 입력 받고
    for (int i = 0; i < N; i++) cin >> v[i];

    // 트리 구성
    build(1, 0, N - 1);

    int Q = M + K;
    while (Q--) {
        int a, b, c;
        cin >> a >> b >> c;

        // 값 갱신
        if (a == 1) {
            v[b - 1] = c;
            update(1, 0, N - 1, b - 1, c);
        }
        // 질의 수행
        else if (a == 2) {
            cout << query(1, 0, N - 1, b - 1, c - 1) % MOD << '\n';
        }
    }

    return 0;
}


ll build(int node, int start, int end) {
    if (start == end) return tree[node] = v[start];

    int mid = (start + end) / 2;

    return tree[node] = (build(node * 2, start, mid) * build(node * 2 + 1, mid + 1, end) % MOD);
}

ll update(int node, int start, int end, int index, ll diff) {
    if (index < start || index > end) return tree[node];

    if (start == end) return tree[node] = diff;

    int mid = (start + end) / 2;

    return tree[node] = (update(node * 2, start, mid, index, diff) * update(node * 2 + 1, mid + 1, end, index, diff) % MOD);
}

ll query(int node, int start, int end, int left, int right) {

    if (right < start || left > end) return 1;

    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;

    return (query(node * 2, start, mid, left, right) * query(node * 2 + 1, mid + 1, end, left, right)) % MOD;
}