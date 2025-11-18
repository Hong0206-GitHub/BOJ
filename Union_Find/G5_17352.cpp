#include <bits/stdc++.h>

using namespace std;

vector<int> parent;

// 집합의 루트 노드 찾는 함수
int find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

// 두 값을 하나의 집합에 합치는 함수
void unionFunc(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) parent[b] = a;
}


int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력 받기
    int N;
    cin >> N;

    // 초기 세팅
    parent.resize(N + 1);
    for (int i = 0; i <= N; i++) parent[i] = i;

    // 다리 연결 정보 입력 받기
    for (int i = 0; i < N - 2; i++) {
        int a, b;
        cin >> a >> b;

        unionFunc(a, b);
    }

    // 답안 저장용 벡터 선언
    vector<int> answer(2, 0);

    // 먼저 하나의 값을 벡터에 저장
    answer[0] = find(1);

    // 순회하면서 나머지 다른 집합(원소가 하나만 남아있는)
    // 다시 말하면 고립된 섬 번호를 찾아서 답 벡터에 삽입
    for (int i = 2; i <= N; i++) {
        if (answer[0] != find(i)) {
            answer[1] = find(i);
            break;
        }
    }

    // 답 출력
    for (int x : answer) cout << x << ' ';
    cout << '\n';

    return 0;
}