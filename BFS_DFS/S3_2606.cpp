#include <bits/stdc++.h>

using namespace std;

// 깊이 우선 탐색으로 구현
void DFS(vector<vector<int>> &graph, vector<bool> &visited, int &answer, int node);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력 받기
    int N, M;
    cin >> N >> M;

    // 그래프와 방문기록 벡터 선언 및 초기화
    vector<vector<int>> graph(N + 1);
    vector<bool> visited(N + 1, false);

    // 답안 저장 변수
    int answer = 0;

    // 그래프 채우기
    for (int i = 0; i < M; i++) {
        int v, e;
        cin >> v >> e;

        graph[v].push_back(e);
        graph[e].push_back(v);
    }

    // 1번 컴퓨터부터 검사하므로, 1번부터 깊이 우선 탐색
    DFS(graph, visited, answer, 1);

    // 답안 출력
    cout << answer << '\n';

    return 0;
}

// 깊이 우선 탐색 알고리즘
void DFS(vector<vector<int>> &graph, vector<bool> &visited, int &answer, int node) {

    // 먼저 현재 노드 방문 처리
    visited[node] = true;

    // 현재 노드와 연결된 인접 정점들에 대해서
    for (int i: graph[node]) {
        // 방문하지 않은 경우
        if (!visited[i]) {
            // 방문처리 해주고
            visited[i] = true;
            answer++;   // 연결되어있는 것이기 때문에 답안 증가
            DFS(graph, visited, answer, i); // 재귀호출
        }
    }
}