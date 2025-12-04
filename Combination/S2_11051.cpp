#include <bits/stdc++.h>

using namespace std;

// 문제에서 제시한 나눌 수
const int MOD = 10007;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 이항 계수의 변수 입력 받기
    int N, K;
    cin >> N >> K;

    // 벡터 선언 및 초기화
    vector<vector<long long>> D(N + 1, vector<long long>(N + 1, 0));

    // 초기값 설정
    // 0개를 선택할 경우의 수 1, 전체 중 전체를 선택할 경우의 수 1
    for (int i = 0; i <= N; i++) {
        D[i][0] = 1;
        D[i][i] = 1;
    }

    // 점화식
    // 마지막 원소를 선택할 경우 -> 앞의 원소들 중에서 선택할 개수 - 1개만큼 선택해야 함.
    // 마지막 원소를 선택하지 않은 경우 -> 앞의 원소들 중에서 선택할 개수 만큼 선택해야 함.
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            // 나머지 연산 규칙에 따라 벡터에 값 저장
            D[i][j] = ((D[i - 1][j - 1] % MOD) + (D[i - 1][j] % MOD)) % MOD;
        }
    }

    // 답안 출력
    cout << D[N][K] << '\n';

    return 0;
}