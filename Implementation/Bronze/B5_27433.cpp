#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력
    int N;
    cin >> N;

    // 답안 변수
    long long answer = 1;

    // 펙토리얼 계산
    for (int i = N; i > 0; i--) {
        answer *= i;
    }

    // 답안 출력
    cout << answer << '\n';

    return 0;
}