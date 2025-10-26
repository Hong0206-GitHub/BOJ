#include <bits/stdc++.h>

using namespace std;

void BFS(vector<vector<int>> &graph, vector<bool> &visited, int node);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 정점 개수 및 간선 개수 입력 받기
    int N, M;
    cin >> N >> M;

    // 그래프와 방문여부 기록 벡터 선언
    vector<vector<int>> graph(N + 1);
    vector<bool> visited(N + 1, false);

    // 그래프 채우기
    for (int i = 0; i < M; i++) {
        int v, e;
        cin >> v >> e;

        graph[v].push_back(e);
        graph[e].push_back(v);
    }

    // 정렬 수행(간선에 대해서만 오름차순으로)
    for (int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end());

    // 답안 저장용 변수
    int count = 0;

    // 모든 정점에 대해서
    for (int i = 1; i <= N; i++) {
        // 아직 방문이 안된 정점이 있다면
        if (!visited[i]) {
            // 답을 1 증가 시키고
            count++;
            // 너비우선탐색 진행
            BFS(graph, visited, i);
        }
    }

    // 답안 출력
    cout << count << '\n';

    return 0;
}

// 너비 우선 탐색 알고리즘 사용
void BFS(vector<vector<int>> &graph, vector<bool> &visited, int node) {
    
    // 방문해야할 정점을 넣을 큐 선언
    queue<int> q;
    // 일단 시작 노드 큐에 삽입
    q.push(node);
    // 큐에 넣었으므로 해당 정점은 방문할 예정이므로,
    // 방문한 걸로 갱신
    visited[node] = true;

    // 큐가 빌 때까지
    while (!q.empty()) {
        // 현재 노드는 큐의 최상단에 위치
        int now_node = q.front();
        // 빼주고
        q.pop();
        // 해당 간선과 연결된 정점들에 대해
        for (int i : graph[now_node]) {
            if (!visited[i]) { // 방문을 안했다면
                visited[i] = true; // 방문 갱신 해주고
                q.push(i);  // 큐에 삽입
            }
        }
    }
}