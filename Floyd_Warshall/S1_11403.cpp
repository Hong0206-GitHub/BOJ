#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 행렬 크기 입력 받기
    int N;
    cin >> N;

    // 초기화
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, 0));

    // 행렬 입력 받기
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> graph[i][j];
        }
    }

    // 변형된 플로이드 워셜 알고리즘 수행
    // 연결되어있으면 1로 고침
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (graph[i][k] == 1 && graph[k][j] == 1)
                    graph[i][j] = 1;
            }
        }
    }

    // 답안 출력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (graph[i][j] == 1) cout << 1 << ' ';
            else cout << 0 << ' ';
        }
        cout << '\n';
    }


    return 0;
}