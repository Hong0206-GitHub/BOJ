#include <bits/stdc++.h>

using namespace std;

using edge = pair<int, int>;
// V: 정점의 개수, E: 간선의 개수, K: 시작 정점
int V, E, K;

// mdistance는 최단 거리 저장
vector<int> mdistance;

// 방문기록 저장
vector<bool> visited;

// 그래프 정보 저장
vector<vector<edge>> mlist;

// 가중치에 따른 정렬을 수행하기 위한, 우선순위 큐
priority_queue<edge, vector<edge>, greater<edge>> pq;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 정점의 개수, 간선의 개수, 시작 정점 입력
    cin >> V >> E >> K;

    // 각 벡터 초기화
    mdistance.resize(V + 1, INT_MAX);
    visited.resize(V + 1, false);
    mlist.resize(V + 1);

    // 그래프 정보 저장
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        mlist[u].push_back({v, w});
    }

    // 시작 정점 우선순위 큐에 저장
    pq.push({0, K});

    // 시작위치는 거리가 0임
    mdistance[K] = 0;

    // 큐가 빌 때까지 반복
    while (!pq.empty()) {
        // 큐에서 하나 꺼내서
        edge current = pq.top();
        pq.pop();

        // 현재 노드가 방문상태면
        int c_v = current.second;
        // 건너 뛰고
        if (visited[c_v]) continue;

        // 방문여부 기록해주고
        visited[c_v] = true;

        // 해당 정점과 연결된 정점들에 대해
        for (size_t i = 0; i < mlist[c_v].size(); i++) {
            edge temp = mlist[c_v][i];
            // 다음 노드
            int next = temp.first;
            // 다음 노드로 가기위한 가중치
            int value = temp.second;

            // 저장된 비용보다 현재 탐색된 비용이 더 적으면
            if (mdistance[next] > mdistance[c_v] + value) {
                // 값 갱신 후, 우선순위 큐에 저장
                mdistance[next] = value + mdistance[c_v];
                pq.push({mdistance[next], next});
            }
        }
    }

    // 답안 출력
    for (int i = 1; i <= V; i++) {
        // 방문한 곳에 대해선 연결되어있으므로, 벡터 값 출력
        if (visited[i]) cout << mdistance[i] << '\n';
        // 아니면 연결되지 않은 정점이므로, INF 출력
        else cout << "INF\n";
    }

    return 0;
}