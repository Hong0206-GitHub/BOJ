#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct edge {int start, end, cost;};

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 정점 개수, 시작, 끝 정점, 간선 개수 입력 받기
    int N, start, end, M;
    cin >> N >> start >> end >> M;

    // 기본 자료형 선언, 초기화때 -inf 임에 주의
    vector<int> price(N);
    vector<edge> mlist;
    vector<ll> mdistance(N, LONG_LONG_MIN);

    // 그래프 만들기(드는 비용이므로, * -1)
    for (int i = 0; i < M; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;

        mlist.push_back({start, end, cost * -1});
    }

    // 버는 돈 입력 받기
    for (int i = 0; i < N; i++) cin >> price[i];

    // 시작 위치에 따른 초기값 설정
    // 이동 비용은 들지 않으면서, 버는 돈으로만 초기화 하면 됨
    mdistance[start] = price[start];

    // 벨만 포드 알고리즘 수행
    // 최대값을 출력해야하므로, 최대값을 갱신해줌
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M; j++) {
            edge temp = mlist[j];
            
            int start = temp.start;
            int end = temp.end;
            int cost = temp.cost;

            if (mdistance[start] != LONG_LONG_MIN && mdistance[end] < mdistance[start] + price[end] + cost) {
                mdistance[end] = mdistance[start] + price[end] + cost;
            }
        
        }
    }

    // 사이클이 있는 노드들 저장할 벡터 선언
    vector<int> cycleNodes;

    // 벨만포드 알고리즘 한번 더 수행하면서 사이클이
    // 존재하는 노드들 저장
    for (int i = 0; i < M; i++) {
        edge temp = mlist[i];
        
        int start = temp.start;
        int end = temp.end;
        int cost = temp.cost;
        
        if (mdistance[start] != LONG_LONG_MIN && mdistance[end] < mdistance[start] + price[end] + cost) {
            cycleNodes.push_back(end);
        }
    }

    // BFS 수행을 위한 그래프 및 방문기록 벡터 선언
    vector<vector<int>> graph(N);
    vector<bool> visited(N, false);

    for (int i = 0; i < M; i++) {
        graph[mlist[i].start].push_back(mlist[i].end);
    }


    // BFS를 수행함
    // 모든 사이클이 존재하는 노드들에 대해
    for (size_t i = 0; i < cycleNodes.size(); i++) {
        fill(visited.begin(), visited.end(), false);
        
        // 큐 선언
        queue<int> q;
        // 초기값 넣어주고
        q.push(cycleNodes[i]);
        // 방문기록 남겨주고
        visited[cycleNodes[i]] = true;


        // 큐가 빌 때까지 
        while (!q.empty()) {

            // 큐에서 하나 꺼내서
            int current = q.front();
            q.pop();

            // 사이클 생성이 가능하다면,
            // Gee 출력 후 종료
            if (current == end) {
                cout << "Gee\n";
                return 0;
            }

            // 아니면 연결된 정점들에 대해 BFS 반복 수행 
            for (size_t j = 0; j < graph[current].size(); j++) {
                if (!visited[graph[current][j]]) {  
                    q.push(graph[current][j]);
                    visited[graph[current][j]] = true;

                }
            }
        }
    }

    // 종료 정점에 도달 할 수 없다면 gg 출력 아니면 최대값 출력
    if (mdistance[end] == LONG_LONG_MIN) cout << "gg\n";
    else cout << mdistance[end] << '\n';


    return 0;
}