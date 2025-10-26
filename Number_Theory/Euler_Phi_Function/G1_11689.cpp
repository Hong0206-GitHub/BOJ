#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력 받기
    ll N;
    cin >> N;

    // 답안 저장용 변수
    ll result = N;

    // 오일러피 함수 핵심
    for (ll i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            result = result - result / i;
            while (N % i == 0) N /= i;
        }
    }

    // 반복문에서 제곱근까지만 탐색했으므로, 1개의 소인수가 누락되었는지
    // 확인해주어야 함.
    if (N > 1) result = result - result / N;

    cout << result << '\n';

    return 0;
}