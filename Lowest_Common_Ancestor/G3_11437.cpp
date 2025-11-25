#include <bits/stdc++.h>

using namespace std;

// 기본 자료형 및 변수 선언
static int N, M;
static vector<vector<int>> tree;
static vector<int> depth;
static vector<int> parent;
static vector<bool> visited;

// 함수 선언
int excuteLCA(int a, int b);
void BFS(int node);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력 받기
    cin >> N;

    // 사이즈 재정의
    tree.resize(N + 1);
    depth.resize(N + 1);
    parent.resize(N + 1);
    visited.resize(N + 1);

    // 그래프 채우기
    for (int i = 0; i < N - 1; i++) {
        int s, e;
        cin >> s >> e;

        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    // 너비우선탐색 진행
    BFS(1);

    // 입력받기
    cin >> M;

    // 두 노드의 최소공통조상 출력
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        int LCA = excuteLCA(a, b);
        cout << LCA << '\n';
    }

    return 0;
}

// 최소공통조상 찾는 알고리즘
int excuteLCA(int a, int b) {

    // 무조건 a노드의 깊이를 더 깊게
    if (depth[a] < depth[b]) {
        int temp = a;
        a = b;
        b = temp;
    }

    // 두 깊이가 같아질 때까지 a 위로 올리기
    while (depth[a] != depth[b]) a = parent[a];
    
    // 두 노드가 같을 때까지 서로 올리기
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }

    return a;
}

// 너비우선탐색 알고리즘
void BFS(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    // 현재 상태를 저장할 변수 선언
    int level = 1;
    int now_size = 1;
    int count = 0;

    while (!q.empty()) {
        int now_node = q.front();
        q.pop();

        for (int next : tree[now_node]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                depth[next] = level;
                parent[next] = now_node;
            }
        }

        count++;

        // 변수 초기화
        if (count == now_size) {
            count = 0;
            now_size = q.size();
            level++;
        }
    }
}