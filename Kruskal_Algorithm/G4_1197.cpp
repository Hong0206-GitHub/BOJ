#include <bits/stdc++.h>

using namespace std;

// 크루스칼 알고리즘 사용
void munion(int a, int b);
int find(int a);

// 우선순위 결정 용 구조체 선언
typedef struct Edge {
    int s, e, v;
    bool operator > (const Edge &temp) const {
        return v > temp.v;
    }
};


vector<int> parent;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력받기
    int N, M;
    cin >> N >> M;

    // 우선순위 큐 선언
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    parent.resize(N + 1);

    // 초기값 세팅
    for (int i = 0; i <= N; i++) parent[i] = i;

    // 값 입력 받아서 우선순위 큐에 삽입
    for (int i = 0; i < M; i++) {
        int s, e, v;
        cin >> s >> e >> v;

        pq.push(Edge{s, e, v});
    }
    
    int useEdge = 0;
    int result = 0;

    while (useEdge < N - 1) {
        Edge now = pq.top();
        pq.pop();

        // 연결되어있지 않으면, 연결
        if (find(now.s) != find(now.e)) {
            munion(now.s, now.e);
            useEdge++;  // 엣지 증가
            result += now.v;    // 답안 갱신
        }
    }

    // 답안 출력
    cout << result << '\n';

    return 0;
}

void munion(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) parent[b] = a;
}

int find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}