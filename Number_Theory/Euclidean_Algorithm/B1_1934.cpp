#include <bits/stdc++.h>

using namespace std;

// 최대공약수 구하는 함수
// 유클리드 호제법 사용
// 두 수의 나머지가 0이 될때까지 반복함
// a는 b로 갱신하고,
// b는 a % b의 값으로 갱신함
int gcd(int a, int b) {
    while (a % b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }

    return b;
}

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 테스트 횟수 입력 받기
    int T; 
    cin >> T;

    // 테스트 횟수만큼
    while (T--) {
        // 두 수 입력받고
        int a, b;
        cin >> a >> b;

        // 최대공약수 구하고
        int g = gcd(a, b);

        // 최소공배수는 두 수의 곱 / 최대공약수로 구할 수 있음
        cout << (a * b / g) << '\n';
    }

    return 0;
}