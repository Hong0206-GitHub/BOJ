#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> party;
vector<int> parent;

// Union-Find 알고리즘 용 함수 구현
int find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

void unionFunc(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) parent[b] = a;
}

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 변수 입력 받고
    int N, M, T;
    cin >> N >> M >> T;

    // 해당 입력값으로 초기 설정
    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) parent[i] = i;

    // 진실을 아는 사람 저장할 벡터 선언
    vector<int> trust(T);

    // 진실을 아는 사람 번호 저장
    for (int i = 0; i < T; i++) cin >> trust[i];

    // 파티 정보 저장
    party.resize(M);

    // 파티 정보 입력 받아 저장
    for (int i = 0; i < M; i++) {
        int party_size;
        cin >> party_size;

        for (int j = 0; j < party_size; j++) {
            int temp;
            cin >> temp;
            party[i].push_back(temp);
        }
    }


    // 합집합 생성
    for (int i = 0; i < M; i++) {
        int first_people = party[i][0];
        for (size_t j = 1; j < party[i].size(); j++) {
            unionFunc(first_people, party[i][j]);
        }
    }

    // 답안 저장용 변수
    int answer = 0;

    // 진실을 아는 사람이 포함되어 있는 경우 거짓말을 할 수 없음
    for (int i = 0; i < M; i++) {
        bool isPossible = true;
        int cur = party[i][0];

        for (int j = 0; j < T; j++) {
            if (find(cur) == find(trust[j])) {
                isPossible = false;
                break;
            }
        }
        if (isPossible) answer++;
    }

    // 답안 출력
    cout << answer << '\n';

    return 0;
}