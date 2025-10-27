#include <bits/stdc++.h>

using namespace std;

// 자료형 선언
using edge = pair<int, int>;

// 필요한 자료형들 선언
static vector<vector<edge>> graph;
static vector<int> m_distance;
static vector<bool> visited;

// 함수 선언
void BFS(int node);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 개수 입력 받기
    int N;
    cin >> N;

    // 사이즈 재설정 및 초기화
    graph.resize(N + 1);
    visited = vector<bool>(N + 1, false);
    m_distance = vector<int>(N + 1, 0);

    // 개수만큼 반복
    for (int i = 0; i < N; i++) {

        // 정점 입력 받고
        int S;
        cin >> S;

        // 무한 반복
        while (true) {
            int v, e;   // 정점과 그 거리 입력 받기
            cin >> v;   // 먼저 정점만 입력받아서
            if (v == -1) break; // 해당 값이 -1이면 종료
            cin >> e;   // 아니면 거리도 마저 입력 받고
            // 그래프 채우기
            graph[S].push_back(edge(v, e));
        }
    }

    // 시작노드에서 가장 먼 거리에 있는 정점부터 찾기
    BFS(1);
    int max = 1;
    for (int i = 2; i <= N; i++)
        if (m_distance[max] < m_distance[i])
            max = i;
    
    // 초기화 한 번 해주고, 가장 먼 거리에 있는 정점에서
    // 가장 먼 정점 찾기
    fill(visited.begin(), visited.end(), false);
    fill(m_distance.begin(), m_distance.end(), 0);
    BFS(max);

    // 정렬해서
    sort(m_distance.begin(), m_distance.end());

    // 가장 큰 값 출력
    cout << m_distance[N] << '\n';

    return 0;
}

// 너비 우선 탐색 알고리즘 사용
void BFS(int node) {
    // 큐 선언
    queue<int> q;
    
    // 해당 노드 방문처리 하고 큐에 삽입
    visited[node] = true;
    q.push(node);

    // 큐가 빌 때까지
    while (!q.empty()) {
        // 노드 하나 꺼내서
        int now_node = q.front();
        q.pop();
        // 그 노드에 들어있는 모든 정점, 거리 쌍에 대해
        for (edge i : graph[now_node]) {
            // 방문한 정점이 아니라면
            if (!visited[i.first]) {
                // 방문처리 해주고, 큐에 삽입
                visited[i.first] = true;
                q.push(i.first);
                // 거리 갱신, 정점 = 현재 정점 + 거리
                m_distance[i.first] = m_distance[now_node] + i.second;
            }
        }
    }
}