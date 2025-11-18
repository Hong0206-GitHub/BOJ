#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 건물 개수 입력 받기
    int N;
    cin >> N;

    // 기본 저장 벡터 선언
    vector<vector<int>> graph(N + 1);
    vector<int> indegree(N + 1);
    vector<int> self(N + 1);
    vector<int> answer(N + 1);

    // 입력 값 저장하기
    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;

        self[i] = temp;

        while(true) {
            cin >> temp;
            if (temp == -1) break;

            graph[temp].push_back(i);
            indegree[i]++;
        }
    }

    // 위상정렬을 위한 큐 선언
    queue<int> q;

    // 입력차수 0인 노드들 큐에 삽입
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) q.push(i); 
    }

    // 큐가 빌 때 까지 반복
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        // 연결된 노드들에 대해 차수 낮추고, 답안 갱신
        for (int next : graph[now]) {
            indegree[next]--;
            answer[next] = max(answer[next], answer[now] + self[now]);
            if (indegree[next] == 0) q.push(next);  // 진입차수가 0이 되었다면 큐에 삽입
        }
    }

    // 답안 출력
    for (int i = 1; i <= N; i++) 
        cout << answer[i] + self[i] << '\n';

    return 0;
}