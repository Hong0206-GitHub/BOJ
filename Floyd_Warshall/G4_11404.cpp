#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 정점 개수 및 간선 개수 입력 받기
    int n, m;
    cin >> n >> m;

    // 초기화
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INT_MAX));

    // 시작점과 종료점이 같은 곳은 0으로 설정
    for (int i = 0; i <= n; i++) graph[i][i] = 0;

    // 입력 받기
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        // 중복 간선은 가치가 낮은 걸로 선택
        graph[u][v] = min(w, graph[u][v]);
    }

    // 플로이드워셜 알고리즘 수행
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    // 답안 출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == INT_MAX) cout << "0 ";
            else cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}