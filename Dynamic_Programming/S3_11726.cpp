#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력 받기
    int n;
    cin >> n;

    // 테이블 선언
    vector<int> DP(n + 1);
    DP[0] = 0;  // 크기가 0이면 0개
    DP[1] = 1;  // 2x1은 2x1 1개만 들어갈 수 있음
    DP[2] = 2; // 2x2는 2x1 2개랑 1x2 2개가 들어간 총 2가지 방법이 있음

    // 점화식

    // 마지막 타일을 기준으로 2x1 타일이 들어가는 경우
    // 앞부분의 2x(n - 1) 과 동일

    // 마지막 타일을 기준으로 1x2 타일이 들어가는 경우
    // 앞부분의 2x(n - 2) 와 동일
    for (int i = 3; i <= n; i++) {
        DP[i] =(DP[i - 1] + DP[i - 2]) % MOD;
    }

    // 답안 출력
    cout << DP[n] << '\n';

    return 0;
}