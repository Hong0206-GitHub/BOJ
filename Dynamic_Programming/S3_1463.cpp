#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 구하는 수 입력 받기
    int N;
    cin >> N;

    // DP 테이블 선언
    vector<int> DP(N + 1);
    
    DP[1] = 0;

    // 점화식
    // i를 기준으로 연산횟수 저장
    for (int i = 2; i <= N; i++) {
        DP[i] = DP[i - 1] + 1;

        if (i % 2 == 0) DP[i] = min(DP[i], DP[i / 2] + 1);
        if (i % 3 == 0) DP[i] = min(DP[i], DP[i / 3] + 1);
    }

    // 답안 출력
    cout << DP[N] << '\n'; 

    return 0;
}