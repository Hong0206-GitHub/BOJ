#include <bits/stdc++.h>

using namespace std;
using edge = pair<int, int>;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 정점 개수, 간선 개수 입력 받기
    int V, E;
    cin >> V >> E;
    
    // 자료형 초기화
    vector<int> mdistance(V + 1, INT_MAX);
    vector<bool> visited(V + 1, false);
    vector<vector<edge>> mlist(V + 1);
    priority_queue<edge, vector<edge>, greater<edge>> pq;

    // 그래프 채우기
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        mlist[u].push_back({v, w});
    }

    // 시작 정점, 도착 정점 정보 입력 받기
    int a, b;
    cin >> a >> b;

    // 시작 정점은 거리 0, 도착 시작정점임
    pq.push({0, a});
    // 시작정점에 대한거리는 0임
    mdistance[a] = 0;

    // 큐가 빌 때까지
    while (!pq.empty()) {

        // 하나 꺼내와서
        edge current = pq.top();
        pq.pop();

        // 해당 정점이 방문상태면 건너뛰고, 아니면 방문기록 남겨서 계속 실행
        int c_v = current.second;
        if (visited[c_v]) continue;
        visited[c_v] = true;

        // 해당 정점과 연결된 정점들에 대해
        for (size_t i = 0; i < mlist[c_v].size(); i++) {
            edge temp = mlist[c_v][i];

            int next = temp.first;
            int weight = temp.second;

            // 거리가 갱신 가능하면 갱신하고, 큐에 삽입
            if (mdistance[next] > mdistance[c_v] + weight) {
                mdistance[next] = mdistance[c_v] + weight;
                pq.push({mdistance[next], next});
            }
        }
    }

    // 답안 출력
    cout << mdistance[b] << '\n';

    return 0;
}