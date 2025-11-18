#include <bits/stdc++.h>

using namespace std;

// 노드 벡터
vector<int> parent;

// 해당 노드의 루트 노드를 찾는 함수
// 재귀적으로 호출하여 경로 압축 수행
int find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

// 두 노드를 하나의 집합으로 합치는 함수
void unionFunc(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) parent[b] = a;
}

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 값 입력 받기
    int n, m;
    cin >> n >> m;

    // 초기 세팅
    // 초기에는 자기 자신이 루트노드임
    parent.resize(n);
    for (int i = 0; i < n; i++) parent[i] = i;

    // 값을 입력 받으면서
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        // 두 노드의 루트 노드가 다른 경우,
        // 하나의 집합으로 합침
        if (find(a) != find(b)) unionFunc(a, b);
        // 같은 경우는 사이클이 생긴 것이므로 횟수 출력 후
        // 프로그램 종료
        else {
            cout << i << '\n';
            return 0;
        }
    }

    // 위에서 걸러지지 않은 경우,
    // 사이클이 끝까지 생기지 않은 것으로 0 출력
    cout << 0 << '\n';

    return 0;
}