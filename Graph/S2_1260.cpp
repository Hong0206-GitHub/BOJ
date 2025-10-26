#include <bits/stdc++.h>

using namespace std;

// 함수 선언부
void  BFS(vector<vector<int>> &graph, vector<bool> &visited, int node);
void  DFS(vector<vector<int>> &graph, vector<bool> &visited, int node);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);
    
    // 정점 개수, 간선 갯수, 시작노드 입력받기
    int N, M, V;
    cin >> N >> M >> V;

    // 그래프와 방문여부 기록하는 벡터 선언
    vector<vector<int>> graph(N + 1);
    vector<bool> visited(N + 1, false);

    // 그래프 채우기
    for (int i = 0; i < M; i++) {
        int v, e;
        cin >> v >> e;

        // 양방향 그래프이므로, 양방향 모두 푸시
        graph[v].push_back(e);
        graph[e].push_back(v);
    }

    // 작은 노드 순으로 방문한다고 하였으므로, 간선부분 정렬 수행
    for (int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end());

    // 답안 출력부
    DFS(graph, visited, V);
    cout << '\n';
    // 방문여부 벡터 기본값으로 초기화
    fill(visited.begin(), visited.end(), false);
    BFS(graph, visited, V);
    cout << '\n';

    return 0;
}

// 너비우선탐색 알고리즘 사용
// 큐를 사용해서 첫 노드 큐에 집어넣고,
// 다음부터 큐에서 꺼내고, 해당 노드를 통해 방문 가능한 정점 큐에 집어넣음
void  BFS(vector<vector<int>> &graph, vector<bool> &visited, int node) {
    // 너비우선탐색의 핵심인 큐 선언
    queue<int> q;
    // 큐에 현재 노드를 집어넣음
    q.push(node);
    // 큐에 집어넣었으므로, 방문 체크
    visited[node] = true;

    // 이제는 큐가 빌 때까지 반복
    while (!q.empty()) {
        // 현재 노드는 큐의 최상단에서 꺼내오면 됨
        int now_node = q.front();
        q.pop(); // 꺼내기
        // 노드 출력
        cout << now_node << ' ';
        
        // 해당 노드와 연결된 다른 정점들에 대해 모두
        for (int i : graph[now_node]) {
            // 방문하지 않은 곳이라면
            if (!visited[i]) {
                // 방문표시 남기고
                visited[i] = true;
                // 큐에 집어넣음
                q.push(i);
            }
        }
    }
}


// 깊이 우선탐색 알고리즘 사용
void  DFS(vector<vector<int>> &graph, vector<bool> &visited, int node) {
    // 일단 현재 노드를 출력함
    cout << node << ' ';
    // 방문여부 갱신해주고
    visited[node] = true;
    // 모든 정점에 대해서
    for (int i : graph[node]) {
        // 아직 해당 정점을 방문하지 않은 경우,
        if (!visited[i]) {
            // 재귀 호출을 통해서 안으로 깊이 파고들어감.
            // (재귀를 사용하지 않는다면) 스택을 사용하는 방식과 동일
            DFS(graph, visited, i);
        }
    }
}