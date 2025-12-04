#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 이항 계수 (N, K) 입력 받기
    int N, K;
    cin >> N >> K;

    // 이차원 벡터 선언, 크기는 N + 1 * N + 1
    vector<vector<int>> D(N + 1, vector<int>(N+ 1));

    // 초기값 설정,
    // i개 중 0개를 선택할 수 있는 방법의 개수는 아무것도 선택하지 않는 것 1개 뿐임
    // i개 중 i개를 선택할 수 있는 방법의 개수는 모든 원소를 선택하는 것 1개 뿐임
    for (int i = 0; i <= N; i++) {
        D[i][0] = 1;
        D[i][i] = 1;
    }

    // 점화식
    // 벡터 채우기
    // 범위는 선택 할 수 있는 개수는 i개를 넘을 수 없음.
    // 또한 j == i의 경우는 위 초기값에서 1로 설정해 놓았기 때문에, 수정해서는 안 됨
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
        }
    }

    // 답안 출력
    cout << D[N][K] << '\n';

    return 0;
}