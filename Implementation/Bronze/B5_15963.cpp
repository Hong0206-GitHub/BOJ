#include <bits/stdc++.h>
using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 두 정수 입력 받기
    long long a, b;
    cin >> a >> b;

    // 답안 저장 변수
    int answer = 0;

    // 같은 값이면 1, 아니면 0
    if (a == b) answer = 1;

    // 출력
    cout << answer << '\n';

    return 0;
}
