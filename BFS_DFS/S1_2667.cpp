#include <bits/stdc++.h>

using namespace std;

// 필요한 자료형 및 변수 선언 및 초기화
static int dx[] = {0, 1, 0, -1};
static int dy[] = {1, 0, -1, 0};
vector<vector<int>> graph;
vector<vector<bool>> visited;
vector<int> answer;
static int temp = 0;
static int N;

// 너비우선탐색 알고리즘 사용
void BFS(int i, int j);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 크기 입력 받기
    cin >> N;

    // 크기에 맞춰 벡터 크기 재설정
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

    // 방문할 수 있는 곳에대해 너비우선탐색 진행
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] == 1 && !visited[i][j]) {
                temp = 0;
                BFS(i, j);
                answer.push_back(temp);
            }
        }
    }

    // 오름차순 출력을 위한 정렬 수행
    sort(answer.begin(), answer.end());
    
    // 답안 출력
    cout << answer.size() << '\n';
    for (int i : answer) cout << i << '\n';

    return 0;
}

// 너비우선 탐색 알고리즘
void BFS(int i, int j) {

    // 큐 선언
    queue<pair<int, int>> q;
    visited[i][j] = true;
    // 큐에는 쌍으로 넣음
    q.push({i, j});

    // 큐가 빌 때 까지 반복
    while (!q.empty()) {
        // 하나 꺼내서 각각 x, y 좌표로 저장
        int x = q.front().first;
        int y = q.front().second;
        q.pop();        
        temp++; // 이 과정에서 건물 수 증가
    
        for (int k = 0; k < 4; k++) {
            // 이동 할 좌표 계산
            int nx = dx[k] + x;
            int ny = dy[k] + y;

            // 갈 수 있는 범위이고
            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                // 아직 방문하지 않았고, 갈 수 있는 곳이라면
                if (graph[nx][ny] == 1 && !visited[nx][ny]) {
                    q.push({nx, ny});   // 큐에 삽입
                    visited[nx][ny] = true; // 방문처리
                }
            }
        }
    }
    
}