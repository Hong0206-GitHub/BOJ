#include <bits/stdc++.h>

using namespace std;

// 2차원 벡터 크기
static int N, M;
// 이동할 델타 값
static int dx[] = {0, 1, 0, -1};
static int dy[] = {1, 0, -1, 0};

void BFS(int i, int j);

// 2차원 벡터와 2차원 방문 여부 판단 벡터
static vector<vector<int>> graph;
static vector<vector<bool>> visited;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 2차원 벡터 크기 입력 받기
    cin >> N >> M;

    // 기초 세팅
    graph = vector<vector<int>>(N, vector<int>(M));
    visited = vector<vector<bool>>(N, vector<bool>(M, false));

    // 2차원 벡터 채우기
    for (int i = 0; i < N; i++) {
        
        string str;
        cin >> str;
        
        for (int j = 0; j < M; j++) {
            graph[i][j] = str[j] - '0';
        }
    }

    // 너비 우선 탐색 호출
    BFS(0, 0);

    // graph에 저장되어있는 값이 거리이므로,
    // 목적지인 [N-1][M-1]에 저장된 값 출력
    cout << graph[N - 1][M - 1] << '\n';

    return 0;
}

// 너비 우선 탐색 알고리즘
void BFS(int i, int j) {
    // 에 필요한 큐 선언
    queue<pair<int, int>> q;
    // 시작 좌표 큐에 삽입
    q.push({i, j});

    // 큐가 빌 때까지
    while (!q.empty()) {
        // x, y좌표용 임시 배열
        int arr[2];
        // 각 좌표 저장
        arr[0] = q.front().first;
        arr[1] = q.front().second;
        q.pop();    // 큐에서 제거

        // 방문처리 해주기
        visited[arr[0]][arr[1]] = true;
        
        // 4방향으로 이동하면서
        for (int k = 0; k < 4; k++) {
            int x = arr[0] + dx[k];
            int y = arr[1] + dy[k];
            // 갈 수 있는 범위에서
            if (x >= 0 && y >= 0 && x < N && y < M) {
                // 갈 수 있는 곳이면
                if (graph[x][y] != 0 && !visited[x][y]) {
                    visited[x][y] = true;   // 가서 방문 처리 해주고
                    graph[x][y] = graph[arr[0]][arr[1]] + 1;    // 거리 갱신 해주고
                    q.push({x, y}); // 큐에 해당 좌표 삽입
                }
            }
        }
    }

}