#include <bits/stdc++.h>

using namespace std;

// DP 함수
int DP(int n, vector<int> &memo) {
 
    // 기저조건
    if (n < 0) return 0;
    else if (n == 0) return 1;
 
    // 이미 계산된 값이 있다면, 그것을 사용
    if (memo[n] != -1) return memo[n];
    
    // 점화식
    memo[n] = DP(n - 1, memo) + DP(n - 2, memo) + DP(n - 3, memo);

    return memo[n];
}

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 테스트 케이스 입력 받기
    int T;
    cin >> T;

    // 테스트 케이스만큼 반복
    while (T--) {
        int N;
        cin >> N;

        // look up table인 벡터 선언
        vector<int> memo(N + 1, -1);

        // 재귀(탑 다운 방식)로 답안 출력
        cout << DP(N, memo) << '\n';
    }

    return 0;
}