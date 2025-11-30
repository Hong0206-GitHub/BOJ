#include <bits/stdc++.h>

using namespace std;

// DP(top_down 방식)
int top_down(int n, vector<int> &memo) {
 
    // 기저조건
    if (n < 0) return 0;
    else if (n == 0) return 1;
 
    // 이미 계산된 값이 있다면, 그것을 사용
    if (memo[n] != -1) return memo[n];
    
    // 점화식
    memo[n] = top_down(n - 1, memo) + top_down(n - 2, memo) + top_down(n - 3, memo);

    return memo[n];
}

// DP(bottom_up 방식)
int bottom_up(int n) {
    // 기저 조건
    if (n == 0) return 1;
    else if (n < 0) return 0;

    // 공간복잡도를 줄이기 위해 3개의 변수만 사용
    // 문제 특성 상 하위 3개의 문제의 답안 사용하고 나머지는 버림
    int temp1 = 0, temp2 = 0, temp3 = 1;
    int current = 0;

    // 반복문 사용(값 갱신)
    for (int i = 1; i <= n; i++) {
        current = temp1 + temp2 + temp3;
        temp1 = temp2;
        temp2 = temp3;
        temp3 = current;
    }

    return current;
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
        cout << top_down(N, memo) << '\n';
        //cout << botton_up(N) << '\n';   
    }

    return 0;
}