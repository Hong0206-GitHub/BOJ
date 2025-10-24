#include <bits/stdc++.h>
using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 변수 저장
    double A, B, C;
    cin >> A >> B >> C;

    // 답안 도출 및 출력
    int answer = (A * B / C > A / B * C) ? A * B / C : A / B * C;
    cout << answer << '\n';
    return 0;
}
