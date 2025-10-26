#include <bits/stdc++.h>

using namespace std;

void BFS(vector<vector<int>> &tree, vector<bool> &visited, vector<int> &answer, int root);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 노드 개수 입력 받기
    int N;
    cin >> N;

    // 트리, 답안 저장, 방문 기록 저장 벡터 선언 및 초기화
    vector<vector<int>> tree(N + 1);
    vector<int> answer(N + 1);
    vector<bool> visited(N + 1, false);

    // 트리 채우기
    for (int i = 0; i < N - 1; i++) {
        int v, e;
        cin >> v >> e;

        tree[v].push_back(e);
        tree[e].push_back(v);
    }

    // 너비 우선 탐색 함수 호출
    BFS(tree, visited, answer, 1);

    // 답안 출력
    for (int i = 2; i <= N; i++) cout << answer[i] << '\n';

    return 0;
}

// 너비 탐색 알고리즘 함수
void BFS(vector<vector<int>> &tree, vector<bool> &visited, vector<int> &answer, int root) {
    queue<int> q;   // 큐 선언
    q.push(root);   // 큐에 집어넣고
    visited[root] = true;   // 기록 남기기

    while (!q.empty()) {    // 큐가 빌때까지    
        int now_node = q.front();   // 큐에서 하나 빼서
        q.pop();

        // 해당 노드의 인접 노드들에 대해
        for (int i : tree[now_node]) {
            if (!visited[i]) {  // 아직 방문 안했다면
                visited[i] = true;  // 방문기록 남기고
                answer[i] = now_node;   // 답에 부모 노드 집어넣고
                q.push(i);  // 큐에 삽입
            }
        }
    }
}