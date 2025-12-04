#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 일수 입력 받기
    int N;
    cin >> N;

    // 시간, 급여 저장할 벡터 선언
    vector<int> T(N + 1);
    vector<int> P(N + 1);

    // 입력 받기
    for (int i = 1; i <= N; i++) {
        cin >> T[i];
        cin >> P[i];
    }

    // DP 테이블 선언
    vector<int> DP(N + 2);

    // 역순으로 계산
    for (int i = N; i >= 1; i--) {
        // 상담을 할 수 없는 경우
        // 다음 날 얻을 수 있는 금액 사용
        if (i + T[i] > N + 1) DP[i] = DP[i + 1];
        
        // 상담을 하지 않는 경우와, 한 경우의 최대값을 사용
        else DP[i] = max(DP[i + 1], P[i] + DP[i + T[i]]);
    }

    // 1일 부터 시작했을 때의 최대 수입 출력
    cout << DP[1] << '\n';

    return 0;
}