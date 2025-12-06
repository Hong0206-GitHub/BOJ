#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000000;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 값 입력 받기
    int N;
    cin >> N;

    // 이차원 벡터 선언
    // 행은 길이, 열은 그 자리 숫자를 의미
    vector<vector<long long>> dp(N + 1, vector<long long>(10));

    // 초기값 세팅
    // 길이가 1인 경우 각 자리에 하나의 숫자만이 계단 수가 될 수 있음
    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }
    
    // 점화식
    // 현재 마지막 자리 숫자인 j가 0인 경우,
    // 바로 앞 자리 숫자는 1만 가능
    // 따라서 dp[len][0] = dp[len - 1][1]
    
    // 현재 마지막 자리 숫자인 j가 9인 경우,
    // 바로 앞 자리 숫자는 8만 가능
    // 따라서 dp[len][9] = dp[len - 1][8];

    // 현재 마지막 자리 숫자인 j가 1 < j < 9인 경우,
    // 바로 앞 자리 숫자는 둘 다 가능
    // 따라서 dp[len][j] = dp[len - 1][j - 1] + dp[len - 1][j + 1];
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            long long val = 0;
            if (j - 1 >= 0) val += dp[i - 1][j - 1];
            if (j + 1 <= 9) val += dp[i - 1][j + 1];
            dp[i][j] = val % MOD;
        }
    }

    // 답안 저장 변수 선언
    long long answer = 0;
    
    // 문제에서 제시된 길이에 따라 가능한 계단 수를 모두 구하면 됨
    for (int i = 0; i <= 9; i++) answer += dp[N][i] % MOD;

    // 답안 출력
    cout << answer % MOD << '\n';

    return 0;
}