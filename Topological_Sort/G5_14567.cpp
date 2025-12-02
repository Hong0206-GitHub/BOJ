#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력값 받기
    int N, M;
    cin >> N >> M;

    // 저장 자료형 선언
    vector<vector<int>> graph(N + 1);
    vector<int> indegree(N + 1);

    // 선수과목 정보 저장
    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        indegree[b]++;
    }

    // 큐 선언
    // 진입 차수가 0인 강의들 큐에 삽입
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    // 답안 저장 벡터
    vector<int> result(N + 1, 1);

    // 큐가 빌 때까지
    while (!q.empty()) {
        
        // 큐의 앞에서 꺼내서
        int now = q.front();
        q.pop();

        for (int next : graph[now]) {
            // 해당 과목의 선수 과목 중 가장 늦는 강의 + 1
            result[next] = max(result[next], result[now] + 1);
            if (--indegree[next] == 0) q.push(next);
        }
    }

    // 답안 출력
    for (int i = 1; i <= N; i++) {
        cout << result[i] << ' ';
    }

    cout << '\n';
    return 0;
}