#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 두 수 입력 받기
    int A, B;
    cin >> A >> B;

    int count = 1;

    // 역방향 탐색
    // B의 1의 자리 숫자가 1이면
    // 연산 적용 가능하므로 10으로 나눈 몫으로 덮음
    while (A < B) {
        if (B % 10 == 1) B /= 10;
        // B가 2의 배수이면, 연산 적용 가능하므로, B를 2로 나눈 몫으로 덮음
        else if (B % 2 == 0) B /= 2;
        else break;     // 이 두 연산에 해당하지 않는 경우 만들 수 없는 수임
        count++;    // 연산 카운트 증가
    }

    // 3항연산자로 두 수가 같아졌으면 연산횟수를 못 만들었으면 -1을 출력
    cout << ((A == B) ? count : -1) << '\n';

    return 0;
}