#include <bits/stdc++.h>

using namespace std;

static int N, M;
vector<vector<int>> tree;
vector<int> depth;
vector<bool> visited;

static int parent[21][100001];
static int kmax;

int excuteLCA(int a, int b);
void BFS(int node);

int main(void) {


    ios::sync_with_stdio(false), cin.tie(NULL);

    cin >> N;

    tree.resize(N + 1);
    depth.resize(N + 1);
    visited.resize(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int s, e;
        cin >> s >> e;

        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    int temp = 1;
    kmax = 0;

    while (temp <= N) {
        temp <<= 1;
        kmax++;
    }

    BFS(1);

    for (int k = 1; k <= kmax; k++) {
        for (int n = 1; n <= N; n++) {
            parent[k][n] = parent[k - 1][parent[k - 1][n]];
        }
    }

    cin >> M;
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        int LCA = excuteLCA(a, b);
        cout << LCA << '\n';
    }

    return 0;
}

int excuteLCA(int a, int b) {
    if (depth[a] > depth[b]) {
        int temp = a;
        a = b;
        b = temp;
    }

    for (int k = kmax; k >= 0; k--) {
        if (pow(2, k) <= depth[b] - depth[a]) {
            if (depth[a] <= depth[parent[k][b]]) {
                b = parent[k][b];
            }
        }
    }

    for (int k = kmax; k >= 0 && a != b; k--) {
        if (parent[k][a] != parent[k][b]) {
            a = parent[k][a];
            b = parent[k][b];
        }
    }

    int LCA = a;
    if (a != b) LCA = parent[0][LCA];

    return LCA;
}

void BFS(int node) {

    queue<int> q;
    q.push(node);
    visited[node] = true;

    int now_size = 1;
    int level = 1;
    int count = 0;

    while (!q.empty()) {
        int now_node = q.front();
        q.pop();

        for (int next : tree[now_node]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;

                depth[next] = level;
                parent[0][next] = now_node;
            }
        }
        count++;

        if (count == now_size) {
            count = 0;
            now_size = q.size();
            level++;
        }

    }

}