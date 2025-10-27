#include <bits/stdc++.h>

using namespace std;

// 너비 우선 탐색 알고리즘 사용
void BFS(vector<vector<int>> &graph, vector<int> &visited, int node);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력값 저장
    int N, M, K, X;
    cin >> N >> M >> K >> X;

    // 기초 벡터들 초기화 및 선언
    vector<vector<int>> graph(N + 1);
    vector<int> visited(N + 1, -1);
    vector<int> answer;

    // 그래프 채우기
    for (int i = 0; i < M; i++) {
        int v, e;
        cin >> v >> e;

        graph[v].push_back(e);
    }

    // 너비 우선탐색 함수 호출
    BFS(graph, visited, X);

    // 거리가 같은 정점들 답 벡터에 저장
    for (int i = 0; i <= N; i++) {
        if (visited[i] == K) answer.push_back(i);
    }

    // 답 벡터가 비어있으면 -1 출력
    if (answer.empty()) cout << -1 << '\n';
    else {  // 비어있지 않다면,
        // 정렬해서 오름차순 순으로
        sort(answer.begin(), answer.end());
        // 모든 원소들 출력
        for (int i : answer) cout << i << '\n';
    }


    return 0;
}

// 너비 우선 탐색
void BFS(vector<vector<int>> &graph, vector<int> &visited, int node) {
    queue<int> q; // 큐 선언
    q.push(node); // 현재 노드 삽입
    visited[node]++;    // 거리 증가

    // 큐가 빌 때까지
    while (!q.empty()) {
        // 큐 최상단 가져와서
        int now_node = q.front();
        q.pop();

        // 연결된 모든 정점에 대해
        for (int i : graph[now_node]) {
            if (visited[i] == -1) { // 방문하지않은 곳이라면,
                // 방문해서 거리 계산
                visited[i] = visited[now_node] + 1;
                q.push(i);  // 큐에 삽입
            }
        }
    }
}