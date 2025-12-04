#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 수 입력 받기
    int N;
    cin >> N;

    // DP 테이블 선언
    vector<int> DP(N + 1);
    DP[0] = 0;  // 0인 이친수는 없음
    DP[1] = 1;  // 1은 그 자체로 이친수 하나임

    // 마지막 숫자에 대해
    // 0이면 N - 1 자리 이친수가 올 수 있음

    // 1이면 11은 불가능 하므로, ...01 만 가능해짐
    // 이 경우 N - 2 자리 모든 이친수가 올 수 있음

    // 따라서 점화식은 피보나치 수열과 동일함
    for (int i = 2; i <= N; i++) {
        DP[i] = DP[i - 1] + DP[i - 2];
    }

    // 답안 출력
    cout << DP[N] << '\n';
    return 0;
}