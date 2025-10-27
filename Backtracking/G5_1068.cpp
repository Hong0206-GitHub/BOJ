#include <bits/stdc++.h>

using namespace std;

// 기본 자료형 선언 및 초기화
static vector<vector<int>> tree;
static vector<bool> visited;
static int N;
static int answer = 0;
static int deleteNode = 0;

// 깊이 우선 탐색 백트래킹 함수 선언
void DFS(int node);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 개수 입력 받기
    int N;
    cin >> N;

    // 사이즈 재정의 및 초기화
    tree.resize(N);
    visited = vector<bool>(N, false);

    // 기본 루트
    int root = 0;

    // 개수 만큼 반복
    for (int i = 0; i < N; i++) {
        int temp;   
        cin >> temp;
        
        // 루트노드가 아니면, 트리에 삽입
        if (temp != -1) {
            tree[temp].push_back(i);
            tree[i].push_back(temp);
        }
        // 루트노드면 해당 노드 루트로 갱신
        else root = i;
    }

    // 삭제할 노드 입력 받기
    cin >> deleteNode;

    // 루트 노드 삭제시 리프 노드가 없으므로 0 출력
    if (deleteNode == root) cout << 0 << '\n';
    else {
        // 다른 노드라면, 백트래킹 함수 호출
        DFS(root);
        // 답안 출력
        cout << answer << '\n';
    }

    return 0;
}

// 깊이 우선 탐색 백트래킹 함수
void DFS(int node) {

    visited[node] = true;
    // 자식 노드 개수
    int cNode = 0;
    for (int i : tree[node]) {
        if (!visited[i] && i != deleteNode) {
            cNode++;    // 자식 노드 개수 증가
            DFS(i);         // 재귀호출
        }
    }

    // 자식 노드가 없으면 리프노드이므로,
    // 답안 증가
    if (cNode == 0) answer++;

}
