#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // N : 가수의 수, M : 보조 PD의 수
    int N, M;
    cin >> N >> M;

    // 기본 자료형 선언
    vector<vector<int>> graph(N + 1);
    vector<int> indegree(N + 1);

    // 입력 받은 횟수동안
    while (M--) {
        // 처음에 받은 수는 담당 가수의 수
        int temp;
        cin >> temp;

        // 이에 맞춰 그래프에 추가
        vector<int> order(temp);
        for (int i = 0; i < temp; i++) {
            cin >> order[i];
        }

        for (int i = 0; i < temp - 1; i++) {
            int a = order[i];
            int b = order[i + 1];
            graph[a].push_back(b);
            indegree[b]++;
        }
    }

    // 큐 선언
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        // 진입차수가 0인 노드들 큐에 삽입
        if (indegree[i] == 0) q.push(i);
    }

    // 답안 값 저장 벡터
    vector<int> result;

    // 큐가 빌 때까지
    while (!q.empty()) {
        // 큐에서 하나 꺼내서
        int now = q.front();
        q.pop();

        result.push_back(now);

        // 진입차수 하나 줄이고 0인 노드들 큐에 삽입
        for (int next : graph[now]) {
            indegree[next]--;
            if (indegree[next] == 0) q.push(next);
        }
    }

    // result 벡터의 사이즈가 N과 다르면 사이클이 생겨 방문하지 못한 노드가 있다는 뜻임
    if (result.size() != N) cout << 0 << '\n';
    else {
        for (int i : result) cout << i << '\n';
    }

    return 0;
}