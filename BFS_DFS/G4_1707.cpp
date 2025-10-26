#include <bits/stdc++.h>

using namespace std;

// 깊이 우선 탐색 알고리즘 사용
void DFS(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &check, bool &is_even, int node);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 테스트 케이스 입력 받기
    int K;
    cin >> K;

    // 테스트 케이스 만큼 만
    while (K--) {
        // 정점과 간선 개수 입력 받기
        int N, M;
        cin >> N >> M;

        // 필요한 것들 초기화
        vector<vector<int>> graph(N + 1);
        vector<bool> visited(N + 1, false);
        vector<int> check(N + 1);

        bool is_even = true;

        // 그래프 채우기
        for (int i = 0; i < M; i++) {
            int v, e;
            cin >> v >> e;

            graph[v].push_back(e);
            graph[e].push_back(v);
        }

        // 모든 정점에 대해서 깊이 우선 탐색 실행
        // 이진이 아니면 그냥 break
        for (int i = 1; i <= N; i++) {
            if (is_even) DFS(graph, visited, check, is_even, i);
            else break;
        }

        // 답안 출력
        if (is_even) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

void DFS(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &check, bool &is_even, int node) {

    visited[node] = true;
    for (int i : graph[node]) {
        if (!visited[i]) {
            check[i] = (check[node] + 1) % 2;
            DFS(graph, visited, check, is_even, i);
        }

        else if (check[i] == check[node]) is_even = false;
    }

}