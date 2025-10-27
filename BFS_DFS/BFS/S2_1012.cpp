#include <bits/stdc++.h>

using namespace std;

// 필요한 자료형 및 변수 선언 및 초기화
vector<vector<int>> graph;
vector<vector<bool>> visited;
static int N, M, K;
static int answer = 0;
static int dx[] = {0, 1, 0, -1};
static int dy[] = {1, 0, -1, 0};

// 함수 선언
void BFS(int i, int j);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 테스트 횟수 입력 받기
    int T;
    cin >> T;

    while (T--) {

        // 가로 크기, 세로 크기, 배추 개수 입력 받기
        cin >> M >> N >> K;

        // 해당 크기로 벡터 초기화
        graph = vector<vector<int>>(N, vector<int>(M, 0));
        visited = vector<vector<bool>>(N, vector<bool>(M, false));
        answer = 0;

        // 배추 채우기
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> y >> x;

            graph[x][y] = 1;
        }

        // 갈 수 있는 곳에 대해 너비 우선 탐색 진행
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (graph[i][j] == 1 && !visited[i][j]) {
                    answer++;
                    BFS(i, j);
                }
            }
        }
        // 답안 출력
        cout << answer << '\n';
    }

    return 0;
}

// 너비우선탐색 알고리즘 사용
void BFS(int i, int j) {

    // 큐 선언
    queue<pair<int, int>> q;
    q.push({i, j}); // 큐에 집어넣고
    visited[i][j] = true;   // 방문 처리

    // 큐가 빌 때 까지 반복
    while (!q.empty()) {
        // 큐에서 각 값 꺼내기
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 4방향 갈 수 있는지 탐색
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            // 유효한 범위이면서
            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                // 아직 안갔으면서 갈 수 있으면
                if (graph[nx][ny] == 1 && !visited[nx][ny]) {
                    q.push({nx, ny});   // 큐에 넣고
                    visited[nx][ny] = true; // 방문처리
                }
            }
        
        }
    }
}