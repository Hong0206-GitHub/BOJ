#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 학생 수 및 비교 횟수 입력 받기
    int N, M;
    cin >> N >> M;

    // 위상정렬을 위한 진입 차수 및 원본 벡터 선언
    vector<vector<int>> graph(N + 1);
    vector<int> indegree(N + 1);

    // 값 벡터에 집어 넣기
    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;

        indegree[e]++;
        graph[s].push_back(e);
    }

    // 위상 정렬을 위한 큐 선언
    queue<int> q;

    // 진입차수가 0인 노드들 삽입
    for (int i = 1; i <= N; i++) 
        if (indegree[i] == 0) q.push(i);

    // 큐가 빌 때 까지
    while (!q.empty()) {
        int now = q.front();    // 큐의 앞에서 꺼내와서
        q.pop();

        // 출력하고
        cout << now << ' ';

        // 해당 노드가 가리키는 값들에 대해
        for (int next : graph[now]) {
            indegree[next]--;   // 진입차수 하나 빼주고
            if (indegree[next] == 0) q.push(next);  // 진입차수가 0이 되었다면 큐에 삽입
        }
    }

    // 답안 보정용
    cout << '\n';

    return 0;
}