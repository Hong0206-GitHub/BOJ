#include <bits/stdc++.h>

using namespace std;

// 너비우선탐색으로 구현
void BFS(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &answer, int node);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 정점 및 간선 개수 입력 받기
    int N, M;
    cin >> N >> M;

    // 그래프, 방문기록, 정답 벡터 선언 및 초기화
    vector<vector<int>> graph(N + 1);
    vector<int> answer(N + 1, 0);
    vector<bool> visited(N + 1, false);

    // 그래프 채우기
    // 단방향 그래프 이므로 주어진 대로만 입력하기
    for (int i = 0; i < M; i++) {
        int v, e;
        cin >> v >> e;

        graph[v].push_back(e);
    }

    // 모든 정점에 대해서
    // 너비 우선탐색을 진행
    // answer 벡터에 총 방문된 횟수가 누적됨
    for (int i = 1; i <= N; i++) {
        fill(visited.begin(), visited.end(), false);
        BFS(graph, visited, answer, i);
    }

    // answer 벡터에서 최대값 찾기(가장 많이 방문된 정점을 찾기 위함)
    int max_val = INT_MIN;
    for (int i = 1; i <= N; i++) 
        if (max_val < answer[i])
            max_val = answer[i];

    // 가장 많이 방문된 정점 찾아서 출력
    for (int i = 1; i <= N; i++)
        if (max_val == answer[i])
            cout << i << ' ';
    cout << '\n';

    return 0;
}


// 너비 우선 탐색 알고리즘
void BFS(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &answer, int node) {
    // 큐 선언해서 앞으로 탐색해야할 정점들 집어넣기
    queue<int> q;
    q.push(node);   // 시작 정점 집어넣고,
    visited[node] = true;   // 방문기록

    // 큐가 빌때까지 반복
    while (!q.empty()) {
        // 현재 정점은 큐의 최상단에 위치, 참조하고
        int now_node = q.front();  
        q.pop();    // 빼기
        // 해당 정점에서 갈 수 있는 정점들에 대해
        for (int i : graph[now_node]) {

            // 아직 방문하지 않은 정점들을
            if (!visited[i]) {
                visited[i] = true;  // 방문갱신하고
                q.push(i);  // 큐에 집어넣음
                answer[i]++;    // 해당 정점은 방문되었으므로, answer값 증가
            }
        }
    }
}