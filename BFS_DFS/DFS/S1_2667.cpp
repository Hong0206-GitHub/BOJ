#include <bits/stdc++.h>

using namespace std;

// 기본 벡터 선언
vector<vector<int>> graph;
vector<vector<bool>> visited;
vector<int> answer;

// 기본 변수들 선언 및 초기화
static int N;
static int temp = 0;
static int dx[] = {0, 1, 0, -1};
static int dy[] = {1, 0, -1, 0};

// 함수 선언
void DFS(int i, int j);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력 받기
    cin >> N;

    // 크기에 맞춰 초기화
    graph = vector<vector<int>>(N, vector<int>(N));
    visited = vector<vector<bool>>(N, vector<bool>(N, false));

    // 그래프 채우기
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++) {
            graph[i][j] = str[j] - '0';
        }
    }

    // 갈 수 있는 곳이면 깊이 우선탐색 수행
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == false && graph[i][j] == 1) {
                temp = 0;
                DFS(i, j);
                answer.push_back(temp);
            }
        }
    }

    // 답안을 오름차순으로 출력해야하므로 정렬
    sort(answer.begin(), answer.end());

    // 답안 출력
    cout << answer.size() << '\n';
    for (int i : answer) cout << i << '\n';

    return 0;
}

// 깊이 우선 탐색 알고리즘
void DFS(int i, int j) {

    // 방문 처리 후
    visited[i][j] = true;
    temp++; // 건물 수 증가
    
    // 갈 수 있는 좌표 계산
    for (int k = 0; k < 4; k++) {
        int x = dx[k] + i;
        int y = dy[k] + j;

        // 갈 수 있는 범위이면서 갈 수 있으면서 방문하지 않은 곳이면
        if (x >= 0 && y >= 0 && x < N && y < N) {
            if (visited[x][y] == false && graph[x][y] == 1) {
                DFS(x, y);       // 재귀로 깊이 우선탐색 진행
            }
        }
    }

}