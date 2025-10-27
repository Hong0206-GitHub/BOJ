#include <bits/stdc++.h>

using namespace std;

// 기본 자료형, 변수 선언 및 초기화
vector<vector<int>> graph;
vector<vector<bool>> visited;
static int answer;
static int dx[] = {0, 1, 0, -1};
static int dy[] = {1, 0, -1, 0};
static int M, N, K;

void DFS(int i, int j);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 테스트 횟수 입력 받기
    int T;
    cin >> T;

    while (T--) {
        
        // 가로, 세로, 개수 입력받기
        cin >> M >> N >> K;

        // 해당 크기로 초기화
        graph = vector<vector<int>>(N, vector<int>(M, 0));
        visited = vector<vector<bool>>(N, vector<bool>(M, false));
        answer = 0;

        // 가로길이 부터 입력받으므로, 편의상
        // 뒤집어서 입력받기
        // 여기서 사용한 변수 x는 행, y는 열을 표현
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> y >> x;

            // 배추가 심어진 위치 1로 표시
            graph[x][y] = 1;
        }

        // 배추가 심어진 곳에 대해 깊이 우선 탐색 진행
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j] == false && graph[i][j] == 1) {
                    DFS(i, j);
                    answer++;   // 해당 if 절에 진입했다면, 구간이 하나 있는거임
                }
            }
        }
        // 답안 출력
        cout << answer << '\n';
    }

    return 0;
}

// 깊이 우선 탐색 알고리즘
void DFS(int i, int j) {

    // 현재 위치 방문 체크
    visited[i][j] = true;

    // 4방향 모두 검사해서
    for (int k = 0; k < 4; k++) {
        int x = dx[k] + i;
        int y = dy[k] + j;

        // 갈 수 있는 범위이면서
        if (x >= 0 && y >= 0 && x < N && y < M) {
            // 아직 방문하지 않았으면서 방문 가능한 곳이면 깊이우선탐색 진행
            if (visited[x][y] == false && graph[x][y] == 1) {
                DFS(x, y);
            }
        }
    }

}