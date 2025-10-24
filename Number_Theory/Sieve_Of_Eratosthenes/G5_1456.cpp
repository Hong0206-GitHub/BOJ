#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 문제의 범위에 대한 소수 판별 벡터 선언
    vector<bool> v(1e7 + 1, true);
    v[0] = false;   // 0은 소수가 아님
    v[1] = false;   // 1은 소수가 아님

    // 에라스토테네스의 체 알고리즘 사용
    for (ll i = 2; i * i <= 1e7; i++)
        if (v[i])
            for (size_t j = i * i; j <= 1e7; j += i) v[j] = false; 

    // 입력 값 입력
    ll A, B;
    cin >> A >> B;

    // 답안 저장용 변수
    int count = 0;

    // 벡터의 전체 범위에 대해
    for (ll i = 2; i <= 1e7; i++) {
        // i가 소수라면
        if (v[i]) {
            // 소수의 제곱으로 만들고
            ll temp = i * i;
            // 그 값이 B보다 작거나 같으면 1번 조건 해당
            while (temp <= B) {
                // 그 값이 A 보다 크거나 같다면 2번 조건에 해당하여
                // 카운트 증가
                if (temp >= A) count++;

                // 오버플로우 방지용
                if (temp > B / i) break;

                // 계속해서 i를 곱하면서 지수를 증가시킴
                temp *= i;

            }
        }
    }

    // 답안 출력
    cout << count << '\n';

    return 0;
}