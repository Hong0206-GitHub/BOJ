#include <bits/stdc++.h>

using namespace std;

// 엣지 구조체 선언
struct Edge {int u, v, w;};

// 필요한 벡터 자료형 선언
vector<int> parent;
vector<vector<int>> graph;
vector<vector<bool>> visited;
vector<Edge> edge;

// 4방향 나타내는 배열 선언
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

// 유니온 파인드의 파인드 함수 선언
int find(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

// 유니온 파인드의 유니온 함수 선언
void unionFunc(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) parent[b] = a;
}

// 너비 우선 탐색 함수 선언, r은 행, c는 열, id는 섬 번호
void BFS(int r, int c, int id) {
    queue<pair<int, int>> q;
    q.push({r, c});     // 큐에 넣고
    visited[r][c] = true;   // 방문기록 남기기
    graph[r][c] = id;   // graph에서 섬 번호로 갱신

    while (!q.empty()) {
        auto [cr, cc] = q.front();  // 큐에서 꺼내서 값 분배
        q.pop();

        // 4방향 탐색
        for (int d = 0; d < 4; d++) {
            int nr = cr + dr[d];
            int nc = cc + dc[d];

            // 범위 벗어난 경우 건너띄기
            if (nr < 0 || nc < 0 || nr >= graph.size() || nc >= graph[0].size()) continue;

            // 육지이면서 방문한 적이 없는 경우
            if (graph[nr][nc] == 1 && !visited[nr][nc]) {
                q.push({nr, nc});   // 큐에 삽입하고,
                visited[nr][nc] = true; // 방문기록 남기기
                graph[nr][nc] = id; // 섬 번호로 갱신
            }
        }
    }

}

int main(void) {

    ios::sync_with_stdio(false), cin.tie(NULL);

    // 전체 크기 입력 받기
    int N, M;
    cin >> N >> M;

    // 행렬 크기 조정
    graph.resize(N, vector<int>(M, 0));
    visited.resize(N, vector<bool>(M, false));

    // 그래프 채우기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    // 섬에 번호 붙이기 (BFS호출)
    int landCount = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 육지이면서 방문한적이 없는 곳에 대해 BFS 수행
            if (graph[i][j] == 1 && !visited[i][j]) BFS(i, j, ++landCount);
        }
    }

    // 다리 놓기
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (graph[r][c] == 0) continue; // 바다인 경우 무시
            
            int currentLand = graph[r][c];

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                int len = 0;

                while (nr >= 0 && nc >= 0 && nr < N && nc <M) {
                    if (graph[nr][nc] == currentLand) break; // 이동해서 출발한 섬 번호로 온 경우 무시
                    if (graph[nr][nc] == 0) len++; // 바다면 길이 증가
                    else {
                        // 다른 섬 발견 시 길이 체크 하고 엣지 벡터에 삽입
                        if (len >= 2) edge.push_back(Edge({currentLand, graph[nr][nc], len}));
                        break;
                    }
                    // 바다인 경우 다시 앞으로 나아가야 함.
                    nr += dr[d];
                    nc += dc[d];
                }
            }
        }
    }

    // 유니온 파인드 사용전 초기화
    parent.resize(landCount + 1);
    for (int i = 1; i <= landCount; i++) parent[i] = i;

    // 최소 스패닝 트리를 만들기 위한 정렬
    sort(edge.begin(), edge.end(), [](const Edge &a, const Edge &b) {return a.w < b.w;});

    int count = 0;
    int sum = 0;

    // 같은 집합인지 확인하고, 아니면 하나로 합침
    for (auto &c : edge) {
        if (find(c.u) != find(c.v)) {
            unionFunc(c.u, c.v);
            count++;
            sum += c.w;
        }

        if (count == landCount - 1) break;
    }

    // 스패닝 트리인 경우에 대해선 가중치 출력, 아니면 -1
    if (count == landCount - 1) cout << sum << '\n';
    else cout << -1 << '\n';

    return 0;
}