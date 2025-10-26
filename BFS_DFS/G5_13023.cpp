#include <bits/stdc++.h>

using namespace std;

// 깊이를 기준으로 탐색하는 문제이므로,
// 깊이 우선 탐색 알고리즘을 사용함
void DFS(vector<vector<int>> &graph, vector<bool> &visited, bool &arrive, int node, int depth);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 정점 및 간선 개수 입력 받기
    int N, M;
    cin >> N >> M;

    // 그래프, 방문기록 벡터 선언 및 초기화
    vector<vector<int>> graph(N);
    vector<bool> visited(N);
    bool arrive = false;

    // 그래프 채우기
    for (int i = 0; i < M; i++) {
        int v, e;
        cin >> v >> e;

        graph[v].push_back(e);
        graph[e].push_back(v);
    }

    // 모든 정점에 대해 탐색해야함.
    // 정점에서 선택한 간선에 따라 답이 달라지므로.
    for (int i = 0; i < N; i++) {
        DFS(graph, visited, arrive, i, 1);
        if (arrive) break;
    }

    // 분기에 따라 적절한 답안 출력
    if (arrive) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}


// 깊이 우선 탐색 알고리즘 사용
void DFS(vector<vector<int>> &graph, vector<bool> &visited, bool &arrive, int node, int depth) {

    // 기저 조건
    if (depth == 5 || arrive) {
        arrive = true;
        return;
    }

    // 깊이 우선 탐색 알고리즘
    visited[node] = true;
    for (int i : graph[node]) {
        if (!visited[i]) {
            DFS(graph, visited, arrive, i, depth + 1);
        }
    }
    // 다음 탐색을 위해 방문기록 초기화
    visited[node] = false;
}