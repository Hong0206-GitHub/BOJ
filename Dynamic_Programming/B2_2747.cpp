#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 값 입력 받기
    int N;
    cin >> N;

    // 3변수 사용
    int fn_2 = 0;
    int fn_1 = 1;
    int fn;

    // 피보나치 수열 계산
    for (int i = 1; i <= N; i++) {
        fn = fn_1 + fn_2;
        fn_1 = fn_2;
        fn_2 = fn;
    }

    // n번째 있는 값 출력
    cout << fn << '\n';

    return 0;
}