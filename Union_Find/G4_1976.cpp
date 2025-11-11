#include <bits/stdc++.h>

using namespace std;

// Union-Find 기본 자료형 선언 및 함수 선언
vector<int> route;
vector<int> parent;

int find(int a);
void unionFunc(int a, int b);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력 받기
    int N, M;
    cin >> N >> M;

    // 벡터 사이즈 조정 및 초기값 입력
    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) parent[i] = i;

    // 연결 되어있는 경우에만 합집합 연산
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int connected;
            cin >> connected;
            if (connected) unionFunc(i, j);
        }
    }

    // 여행 갈 경로 입력
    route.resize(M);
    for (int i = 0; i < M; i++) cin >> route[i];

    // 루트부터 모든 도시가 연결되어있는지 판단
    int root = find(route[0]);

    for (int i = 1; i < M; i++) {
        if (find(route[i]) != root) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}

// 원소의 루트 찾기
int find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

// 합집합 연산
void unionFunc(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) parent[b] = a;
}