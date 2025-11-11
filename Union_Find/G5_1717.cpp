#include <bits/stdc++.h>
using namespace std;

// 기본 변수 및 함수 선언
int N, M;
vector<int> parent;

void unionFunc(int a, int b);
int find(int a);
bool checkSame(int a, int b);

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력 받기
    cin >> N >> M;

    // 사이즈 재설정
    parent.resize(N + 1);

    // 원소 채우기
    for (int i = 1; i <= N; i++) parent[i] = i;

    // 질의 수행
    for (int i = 0; i < M; i++) {

        // 값 입력 받기
        int q, a, b;
        cin >> q >> a >> b;

        // 질의 내용에 따라 동작
        if (q == 0) unionFunc(a, b);
        else {
            if (checkSame(a, b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}

// 합집합 만들기
void unionFunc(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

// 두 원소가 같은 집합에 속해있는지를 판단하여 반환하는 함수
bool checkSame(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return 1;
    return 0;
}

// 재귀적으로 올라가서 부모 노드 반환
int find(int a) {
    if (a == parent[a]) return a;
    else return a = find(parent[a]);
}